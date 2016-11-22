#include "reader.h"
#include <QtNetwork>
#include <QProcess>


#include <iostream>

#include <sys/types.h>

#include <sys/ipc.h>

#include <sys/msg.h>
#include <mqueue.h>

#include "../speak/speak.h"

reader::reader(): QThread()
{
    vocabolarioDialog = new DialogShowVocabolario();
    server = new QLocalServer(this);

    if (!server->listen("facilito"))
    {


	server->removeServer("facilito");
	if (!server->listen("facilito"))
    	{
        	currentMsgId = 5;
	        qDebug() << "Errore" << endl;
        	return;
	}
    }
    connect(server, SIGNAL(newConnection()), this, SLOT(readMsg()));

    currentMsgId = -1;

    currentConfigurations.voice = "Maschio";
    currentConfigurations.volume = 1;
    currentConfigurations.speed = 1;
    //int wait;
    currentConfigurations.evidence = true;
    currentConfigurations.showEvidence = true;
    //currentConfigurations.evidenceType = doc.BACKGROUND_COLOR; // c for Color; b for background; u forn underline;
    currentConfigurations.readText = true;
    currentConfigurations.evidenceRow = false;
    currentConfigurations.shortcuts = true;
    currentConfigurations.copybooks = true;

    typeReading = doc.SENTENCE;
    doc.setScansionType(doc.SENTENCE);
    doc.setEvidencetType(doc.BACKGROUND_COLOR);

    doc.setCharColor(0xFF00FF);


}

void reader::loadPagina(QString fileName)
{
    doc.openDocument(fileName.toStdString().c_str());
}



void reader::readMsg()
{
    QLocalSocket *clientConnection = server->nextPendingConnection();
    qint32 msgId;



    connect(clientConnection, SIGNAL(disconnected()), clientConnection, SLOT(deleteLater()));

    QDataStream in(clientConnection);
    in.setVersion(QDataStream::Qt_4_0);

    QByteArray block;

    clientConnection->waitForReadyRead();


    if(clientConnection->bytesAvailable() < sizeof(qint32))
         return;

    in >> msgId;

    clientConnection->disconnectFromServer();


    currentMsgId = msgId;

    if(currentMsgId != -1)
    {
        condMsgId.wakeAll();
        mutex.unlock();
    }




}

void reader::run()
{
//    exec();
    unsigned int sender;
    int err;
    Msg msg;
    QString precWord = "";

    int msgq_id = mq_open("/speakqu", O_RDWR);
    int msgq_id1 = mq_open("/sender", O_RDONLY);

    qDebug() << "prima della connessione";



    //doc.connectCurrentDocument();

    qDebug() << "prima del while";


    while(1)
    {
        if(currentMsgId == -1)
        {

            condMsgId.wait(&mutex);
            QSettings settings("facilitoffice", "office");
            QString color = settings.value("color").toString();
            conf(color);
            doc.connectCurrentDocument();
        }

        qDebug() << "ID " << currentMsgId << endl;

        switch(currentMsgId)
        {
            case 1:
            {
                if(doc.moveNext())
                {
                    QString a(doc.getSelectedText().c_str());
                    a.remove('\"');

                    strcpy(msg.text, a.toStdString().c_str());

                    msg.msgId = 1;
                    // manda testo al player
                    int err = mq_send(msgq_id, (char *) &msg, sizeof(Msg), NULL);

                    qDebug() << "ERR " << err << "MANDATo " << a << endl;


                    mq_attr attr;
                    mq_getattr(msgq_id1,&attr);

                    // wait for message read

                    if((err = mq_receive(msgq_id1, (char *)&msg, attr.mq_msgsize, &sender)) == -1)
                         perror("Receive: ") ;
                    else
                    {
                      cout << "ID ricevuto" << msg.msgId << endl;
                    }
                }
                else
                {
                   strcpy(msg.text, "Hai raggiunto la fine del testo\n");
                   msg.msgId = -1;
                   currentMsgId = -1;
                   // manda testo al player
                   mq_send(msgq_id, (char *) &msg, sizeof(Msg), NULL);
                }
            }
                break;
            case 2:
                {
                    QString word(doc.vocabolario().c_str());
                    if(word != precWord)
                    {
                        emit vocabolario(word);
                        precWord = word;
                    }
                    sleep(1);

                }
                break;
            case 3:
                {

                    emit hideVocabolario();
                    currentMsgId = -1;
                }
                break;
            case 4:
                {
                    emit gestioneVocab();

                    currentMsgId = -1;
                    break;
                }
        case 10:
                //emit showQuaderni();
                //doc.connectCurrentDocument();
                //doc.open("/home/nicola/Documenti/facilitoffice/quaderni/1/template2.odt");
                //currentMsgId = -1;
                break;
        case 20:
                cout << "MANDO 20\n";
                emit showConf();
                currentMsgId = -1;
                break;
            default:
                break;
        }
    }
    mq_close(msgq_id);
    mq_close(msgq_id1);
}

int reader::getId()
{
    return currentMsgId;
}
void reader::conf(QString col)
{
    qDebug() << "SET COLOR " << col << endl;
    doc.setCharColor(col.toLong());
}

void reader::setDialog(DialogShowVocabolario *v)
{
    vocabolarioDialog = v;
}

