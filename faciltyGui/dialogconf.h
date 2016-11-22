#ifndef DIALOGCONF_H
#define DIALOGCONF_H

#include <QtWidgets/QDialog>
#include <QCloseEvent>

namespace Ui {
    class DialogConf;
}

class DialogConf : public QDialog {
    Q_OBJECT
public:
    DialogConf(QWidget *parent = 0);
    ~DialogConf();
    void open();
protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *event);
private:
    Ui::DialogConf *ui;
public slots:
    void setColor();
    void accept() {QDialog::setVisible(false);}
    void reject(){QDialog::setVisible(false);}
signals:
    void conf(QString color);
};

#endif // DIALOGCONF_H
