#ifndef PLAYER_H
#define PLAYER_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <stdio.h>
#include <stdlib.h>
//#include "../../src/facilitoffice.h"
#include "../speak/speak.h"
#include <QtWidgets/QWidget>

class Player : public QThread
{
    Q_OBJECT
    QMutex *mutex;
    QWaitCondition *condition;
   // FacilitOffice doc;
   // Speak speak;
    int init;
public:
    Player(QObject *parent = 0);
   // Player(QMutex *mutex, QWaitCondition *condition, FacilitOffice doc, Speak speak, QObject *parent = 0);
    void run();
    void setMutex(QMutex *mutex);
    void setCondition(QWaitCondition *condition);
   // void setDocument(FacilitOffice &doc);
    void setSpeak(Speak speak);
public slots:
    void ok();
};

#endif // PLAYER_H
