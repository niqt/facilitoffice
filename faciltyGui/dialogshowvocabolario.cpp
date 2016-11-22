#include "dialogshowvocabolario.h"
#include "ui_show_voc_dialog.h"
#include <QDebug>
#include "types.h"
#include <sys/types.h>

#include <sys/ipc.h>

#include <sys/msg.h>
#include <mqueue.h>

DialogShowVocabolario::DialogShowVocabolario(QWidget *parent)
    : QDialog(parent), ui(new Ui::VocabolarioDialogClass)
{
    ui->setupUi(this);
    db = new Db("facdb");
    db->create();
}

void DialogShowVocabolario::show(QString word)
{
    QString descrizione;
    QPixmap pixmap;

    if(db->getInfo(word, descrizione, pixmap))
    {
        ui->descrLabel->setText(descrizione);
        ui->imgLabel->setPixmap(pixmap);
        ui->label->setText(word);
        this->setWindowFlags(Qt::WindowStaysOnTopHint);
        QDialog::show();

    }
}

void DialogShowVocabolario::hide()
{

    QDialog::setVisible(false);
}


void DialogShowVocabolario::setText(QString word)
{

    ui->descrLabel->setText(word);
}

void DialogShowVocabolario::leggi()
{
    Msg msg;
    int msgq_id = mq_open("/speakqu", O_RDWR);
    QString a(ui->label->text());
    a.remove('\"');

    strcpy(msg.text, a.toStdString().c_str());

    msg.msgId = -1;
    // manda testo al player
    mq_send(msgq_id, (char *) &msg, sizeof(Msg), NULL);
    mq_close(msgq_id);
}

void DialogShowVocabolario::upper()
{
    ui->label->setText(ui->label->text().toUpper());
}

void DialogShowVocabolario::closeEvent(QCloseEvent *event)
{

    event->ignore();
    QDialog::setVisible(false);

}
