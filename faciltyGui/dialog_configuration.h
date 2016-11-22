#ifndef DIALOG_CONFIGURATION_H
#define DIALOG_CONFIGURATION_H

//#include <QtGui/QDialog>
#include <QtWidgets/QDialog>
#include "types.h"

namespace Ui
{
    class Dialog;
}

class DialogConfiguration : public QDialog
{
    Q_OBJECT

public:
    DialogConfiguration(QWidget *parent = 0);
    ~DialogConfiguration(){;}
    Configurations getConfigurations(Configurations old, bool &ok);
private:
    Ui::Dialog *ui;
    bool okPushed;
    QRgb color;
private slots:
    void reject();
    void accept();
    void reimposta();
    void play();
    void chooseColor();
};



#endif // DIALOG_CONFIGURATION_H
