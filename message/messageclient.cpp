#include <QtNetwork>
#include <QLocalSocket>

#include "messageclient.h"

MessageClient::MessageClient(QObject *parent) : QObject(parent)
{
    socket = new QLocalSocket(this);

    connect(socket, SIGNAL(error(QLocalSocket::LocalSocketError)), this , SLOT(displayError(QLocalSocket::LocalSocketError)));


}

int MessageClient::sendMsg(int msgId)
{
    socket->abort();

    socket->connectToServer("facilito");



    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);


    out << (qint32)msgId;
    quint16 bs = socket->write(block);
    socket->flush();
    socket->waitForBytesWritten(2000);
qDebug() << "Send\n";
    //socket->disconnectFromServer();

    return 0;
}

void MessageClient::displayError(QLocalSocket::LocalSocketError socketError)
{
    switch (socketError)
    {
    case QLocalSocket::ServerNotFoundError:
        qDebug() << "The host was not found. Please check the host name and port settings.";
        break;
    case QLocalSocket::ConnectionRefusedError:
        qDebug() << "The connection was refused by the peer. Make sure the fortune server is running, and check that the host name and port settings are correct.";
        break;
    case QLocalSocket::PeerClosedError:
        break;
    default:
        qDebug() << "The following error occurred: " << socket->errorString();
    }


}


