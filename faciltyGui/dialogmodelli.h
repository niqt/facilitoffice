#ifndef DIALOGMODELLI_H
#define DIALOGMODELLI_H



#include <QtWidgets/QDialog>

#include "modelli.h"
#include "filemodel.h"
#include "filedelagate.h"
namespace Ui
{
    class DialogModelli;
}



class DialogModelli : public QDialog
{
Q_OBJECT

public:
    DialogModelli(QWidget *parent = 0);
    ~DialogModelli();
    QString modello(QStringList quaderni, QStringList modelli, QStringList &selezionati, QDir baseDir);
private:
    Ui::DialogModelli *ui;
    Modelli *modelli;
    FileModel *fileModello;
    int nQuaderni;
    QStringList _quaderni;
    QDir _baseDir;
    FileDelagate *delegate;
public slots:
    void nuovo();
    void tabChanged(int index);
    void elimina();
};

#endif // DIALOGMODELLI_H
