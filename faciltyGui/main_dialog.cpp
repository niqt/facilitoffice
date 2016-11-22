#include "main_dialog.h"
#include "ui_dialog.h"

#include <QtWidgets/QMessageBox>
#include <QDebug>
#include <QtWidgets/QFileDialog>
#include <QDir>
#include <QtNetwork>

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::MainDialog)
{
    ui->setupUi(this);

    player = new Player();

    connect(ui->esciPushButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->leggiPushButton, SIGNAL(clicked()),  this, SLOT(leggi()));
    connect(ui->sceltePushButton, SIGNAL(clicked()), this, SLOT(scelte()));
    connect(ui->configurazioniPushButton, SIGNAL(clicked()), this, SLOT(configura()));
    connect(ui->evidenzaPushButton, SIGNAL(clicked()), this, SLOT(evidenzia()));
    connect(ui->quaderniPushButton, SIGNAL(clicked()), this, SLOT(quaderni()));
    connect(ui->infoPushButton, SIGNAL(clicked()), this, SLOT(info()));
    connect(ui->stopPushButton, SIGNAL(clicked()), this, SLOT(stop()));

    //ui->leggiPushButton->setDisabled(true);
    ui->stopPushButton->setDisabled(true);

    ui->evidenzaPushButton->setText("Evidenzia a frase");

    officeProcess = 0;
    // Run openoffice
    startOffice();


    // set this window on top

    //this->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::X11BypassWindowManagerHint);


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
    //QRgb color;

    dialogConfiguration = 0;
   // windowQuaderni = 0;
    //typeReading = doc.SENTENCE;
   // doc.setScansionType(doc.SENTENCE);
    //doc.setEvidencetType(doc.BACKGROUND_COLOR);
    //speak.setSpeed(1);

    server = new QLocalServer(this);
    if (!server->listen("facilitoffi"))
    {
        QMessageBox::critical(this, tr("FacilitOffice Server"),
                              tr("Unable to start the server: %1.")
                              .arg(server->errorString()));
        close();
        return;
    }
    connect(server, SIGNAL(newConnection()), this, SLOT(readMsg()));
    currentMsgId = -1;

    //start();

}

MainDialog::~MainDialog()
{
    delete ui;
    if(officeProcess != 0)
        delete officeProcess;
}

void MainDialog::esci()
{
}

void MainDialog::leggi()
{
    qDebug() << "QUA\n";
    ui->stopPushButton->setDisabled(false);

   // player->setDocument(doc);
    player->start();
    //player->run();
    /*if(doc.moveNext())
    {
       QString a(doc.getSelectedText().c_str());
       a.remove('\"');
       //speak.sayText(a.toStdString().c_str());
    }
    else
    {
        speak.sayText("Hai raggiunto la fine del file");
        QMessageBox::warning(this, "Letto tutto", "Hai raggiunto la fine del file", "Ok");
    }*/

}

void MainDialog::configura()
{
    bool ok = false;
    if(dialogConfiguration == 0)
        dialogConfiguration = new DialogConfiguration();

    this->setModal(false);

    Configurations newConfigurations = dialogConfiguration->getConfigurations(currentConfigurations, ok);

    if(ok)
    {
        qDebug() << "Tye " << newConfigurations.evidenceType << endl;
        currentConfigurations = newConfigurations;
        //doc.setScansionType(currentConfigurations.evidenceType);
        //doc.setEvidencetType(currentConfigurations.evidenceType);
        //speak.setSpeed(currentConfigurations.speed);

        /*QFile file(QDir::homePath() + QDir::separator() + ".qcradio");


        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
         return;

        QTextStream out(&file);
        out << dirs.programs << "\n";
        out << dirs.spots << "\n";
        out << dirs.music << "\n";
        out << "5\n";


        file.close();

        dirPrograms = dirs.programs;
        dirSpots = dirs.spots;
        dirMusic = dirs.music;*/
    }


}

void MainDialog::scelte()
{
}

void MainDialog::evidenzia()
{

    typeReading = !typeReading;
    //doc.setScansionType(typeReading);
    /*if(typeReading == doc.SENTENCE)
        ui->evidenzaPushButton->setText("Evidenzia a frase");
    else
        ui->evidenzaPushButton->setText("Evidenzia a parola");*/
}

void MainDialog::quaderni()
{

   /* if(windowQuaderni == 0)
        windowQuaderni = new WindowQuaderni();
    windowQuaderni->show();
*/
    try
    {
         QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                 QDir::homePath(),
                                                 tr("Images (*.odt)"));
        //doc.openDocument("/tmp/test.odt");
       // doc.openDocument(fileName.toStdString().c_str());
        //doc.setCharColor(0xFF00FF);
        //player->setDocument(doc);
        ui->leggiPushButton->setDisabled(false);
        ui->stopPushButton->setDisabled(false);

    }
    catch(...)
    {
        //speak.sayText("Non posso aprire il quaderno scelto");
        QMessageBox::critical(this, "Don't open file", "Don't open file selected", "Ok");
    }
}

void MainDialog::startOffice()
{
    // QString program = "soffice";
    // QStringList arguments;
    // arguments << "-accept=socket,host=localhost,port=2083;urp;StarOffice.ServiceManager";

     //QProcess *officeProcess = new QProcess(this);
     //officeProcess->start(program, arguments);
 }

void MainDialog::close()
{
    QDialog::close();

}

void MainDialog::stop()
{
    //player->terminate();
}

void MainDialog::info()
{
    QMessageBox::aboutQt(this, "About Qt");
}


void MainDialog::readMsg()
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

    //while()
    {



        qDebug() << "Ricevuto " << msgId<< endl;
        currentMsgId = msgId;
        //operation = msgId;
    }

}

void MainDialog::start()
{
    Speak speak;
    while(1)
    {
        if(currentMsgId == 1)
            speak.sayText("We bello");
    }
}
