#include <QtCore/QCoreApplication>
#include "messageclient.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString c(argv[1]);

    MessageClient b;
    b.sendMsg(c.toInt());

    //return a.exec();
    return 0;
}
