#ifndef MESSAGECLIENT_H
#define MESSAGECLIENT_H

#include <QLocalSocket>
#include <QObject>

class MessageClient : public QObject
{
    Q_OBJECT

    public:
        MessageClient(QObject *parent = 0);
        ~MessageClient() {;}
        int sendMsg(int msgId);
    private:
        QLocalSocket *socket;

    public slots:
       void displayError(QLocalSocket::LocalSocketError socketError);

};

#endif // MESSAGECLIENT_H
