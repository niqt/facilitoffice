#ifndef DIALOGETICHETTA_H
#define DIALOGETICHETTA_H


#include <QtWidgets/QDialog>

namespace Ui
{
    class DialogEtichetta;
}



class DialogEtichetta : public QDialog
{
    Q_OBJECT

public:
    DialogEtichetta(QWidget *parent = 0);
    ~DialogEtichetta();
    QString etichetta(QString n);
private:
    Ui::DialogEtichetta *ui;


};

#endif // DIALOGETICHETTA_H
