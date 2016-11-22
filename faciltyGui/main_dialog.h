#ifndef MAIN_DIALOG_H
#define MAIN_DIALOG_H

//#include <QtGui/QDialog>
#include <QtWidgets/QDialog>
#include <QProcess>
#include <QLocalServer>

#include "dialog_configuration.h"
#include "types.h"
//#include "../../src/facilitoffice.h"
#include "../speak/speak.h"
#include "player.h"
#include "windowquaderni.h"
#include "quadernodialog.h"

namespace Ui
{
    class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    MainDialog(QWidget *parent = 0);
    ~MainDialog();
    void openQuadernoDialog(QPushButton *button);
private:


    Ui::MainDialog *ui;
    DialogConfiguration *dialogConfiguration;
    //WindowQuaderni *windowQuaderni;
    QuadernoDialog *quadernoDialog;
    bool isEvidenzia;
    QProcess *officeProcess;
    void startOffice();
    Configurations currentConfigurations;
    //FacilitOffice doc;
    //Speak speak;
    Player *player;
    int typeReading;
    QLocalServer *server;
    int currentMsgId;
    void start();

private slots:
    void esci();
    void leggi();
    void configura();
    void scelte();
    void evidenzia();
    void quaderni();
    void close();
    void stop();
    void info();
    void readMsg();
};

#endif // MAIN_DIALOG_H
