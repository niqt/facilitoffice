#ifndef DIALOGPAGINA_H
#define DIALOGPAGINA_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QMenuBar>
#include <QFile>
#include <QDir>
#include <QSqlQueryModel>

namespace Ui {
    class DialogPagina;
}

class DialogPagina : public QDialog {
    Q_OBJECT
public:
    DialogPagina(QWidget *parent = 0);
    ~DialogPagina();
    void pagina(QString fileNameModello, QString quaderno, QDir baseDir, QString &pathPagina, bool &ok);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogPagina *ui;
    QMenuBar *mb;
    QString _quaderno;
    QString _descrizione;
    QSqlQueryModel *model;
    QDir _baseDir;
    QString _fileNameModello;
    QString _pagina;
    bool _selected;
public slots:
    void nuova();
    void inserisci();
    void elimina();
    void selectedItem(QModelIndex index);
    void apri();
};

#endif // DIALOGPAGINA_H
