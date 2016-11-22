#ifndef READER_H
#define READER_H

#include <QThread>
#include <QLocalServer>

#include <QMutex>
#include <QWaitCondition>
#include "types.h"
#include "../src/facilitoffice.h"
#include "dialogshowvocabolario.h"

class reader : public QThread
{
     Q_OBJECT
    private:
    int currentMsgId;
    QLocalServer *server;
    QMutex mutex;
    QWaitCondition condMsgId;
    FacilitOffice doc;
    Configurations currentConfigurations;
    int typeReading;
    DialogShowVocabolario *vocabolarioDialog;
public:
    reader();
    int getId();
    void run();
    public slots:
    void readMsg();
    void setDialog(DialogShowVocabolario *d);
 signals:
     void vocabolario(QString word);
     void hideVocabolario();
     void gestioneVocab();
     void showQuaderni();
     void showConf();
 public slots:
     void loadPagina(QString);
     void conf(QString);
};

#endif // READER_H
