#include <QtWidgets/QApplication>
#include "main_dialog.h"
#include "reader.h"
#include "dialogvocabolario.h"
#include "dialogshowvocabolario.h"
#include "dialogquaderni.h"
#include "dialogconf.h"
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString program = "soffice";
    QStringList arguments;

    QProcess *officeProcess = new QProcess();
    //officeProcess->start(program, arguments);
    //sleep(60);

    //QProcess *leggiProcess = new QProcess();
    //leggiProcess->start("/usr/local/bin/reader", arguments);
    //sleep(1);

    DialogShowVocabolario vocabolarioDialog;
    DialogVocabolario gestioneVocabolarioDialog;
    DialogConf dialogConf;
    //DialogQuaderni dialogQuaderni;
    arguments << "-accept=socket,host=localhost,port=2083;urp;StarOffice.ServiceManager";

    //QProcess *officeProcess = new QProcess();
    //officeProcess->start(program, arguments);
    //sleep(60);


    QSettings settings("facilitoffice", "office");
    settings.setValue("color", "#ff0000");

    reader *r = new reader();

QObject::connect(r, SIGNAL(vocabolario(QString)), &vocabolarioDialog, SLOT(show(QString)));
QObject::connect(r, SIGNAL(hideVocabolario()), &vocabolarioDialog, SLOT(hide()));
QObject::connect(r, SIGNAL(gestioneVocab()), &gestioneVocabolarioDialog, SLOT(show()));
//QObject::connect(r, SIGNAL(showQuaderni()), &dialogQuaderni, SLOT(show()));
QObject::connect(r, SIGNAL(showConf()), &dialogConf, SLOT(show()));
//QObject::connect(&dialogConf, SIGNAL(conf(QString)), r, SLOT(conf(QString)));
//QObject::connect(&dialogQuaderni, SIGNAL(loadPagina(QString)), r, SLOT(loadPagina(QString)));

//r->setDialog(&vocabolarioDialog);
    r->start();

    //MainDialog w;
    //w.show();
    return a.exec();

}
