#ifndef QUADERNODIALOG_H
#define QUADERNODIALOG_H

#include <QtWidgets/QDialog>

namespace Ui
{
    class DialogQuaderno;
}


class QuadernoDialog : public QDialog
{
    Q_OBJECT
    private:
        Ui::DialogQuaderno *ui;
public:
    QuadernoDialog(QWidget *parent = 0);
    ~QuadernoDialog();
};

#endif // QUADERNODIALOG_H
