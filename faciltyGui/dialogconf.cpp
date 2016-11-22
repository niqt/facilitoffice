#include "dialogconf.h"
#include "ui_dialogconf.h"
#include <QtWidgets/QColorDialog>
#include <QSettings>

DialogConf::DialogConf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConf)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    //QPalette palette;
    //palette.setColor(QPalette::Button, Qt::green);
    ui->labelColor->setStyleSheet("background-color: yellow;");
    //ui->labelColor->setPalette(palette);
}

DialogConf::~DialogConf()
{
    delete ui;
}

void DialogConf::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void DialogConf::closeEvent(QCloseEvent *event)
{

    event->ignore();
    QDialog::setVisible(false);

}

void DialogConf::open()
{
    QDialog::exec();
    QPalette palette = ui->labelColor->palette();
    QColor color = palette.color(QPalette::Window);
    emit conf(color.name());
}

void DialogConf::setColor()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        ui->labelColor->setStyleSheet("background-color: " + color.name() + ";");


        /*QPalette palette;
        palette.setColor(QPalette::Window, color);
        ui->labelColor->setPalette(palette);*/
    }
}
