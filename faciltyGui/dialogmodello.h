#ifndef DIALOGMODELLO_H
#define DIALOGMODELLO_H

#include <QtWidgets/QDialog>

namespace Ui {
    class DialogModello;
}

class DialogModello : public QDialog {
    Q_OBJECT
public:
    DialogModello(QWidget *parent = 0);
    QStringList getModello();
    ~DialogModello();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogModello *m_ui;

private slots:
    void loadModello();
};

#endif // DIALOGMODELLO_H
