#ifndef DIALOGVOCABOLARIO_H
#define DIALOGVOCABOLARIO_H

#include <QtWidgets/QDialog>
#include "db.h"
#include <QPixmap>
#include <QSqlRelationalTableModel>
#include <QCloseEvent>

namespace Ui {
    class DialogVocabolario;
}

class DialogVocabolario : public QDialog
{
    Q_OBJECT
    Q_DISABLE_COPY(DialogVocabolario)
public:
    explicit DialogVocabolario(QWidget *parent = 0);
    virtual ~DialogVocabolario();

protected:
    virtual  void changeEvent(QEvent *e);


private:
    Ui::DialogVocabolario *m_ui;
    bool modify;
    int currentItem;
    Db *db;
    QPixmap img;
    QSqlTableModel *model;
public slots:
    void nuovo();
    void immagine();
    void elimina();
    void save();
    void select(QModelIndex index);
    void chiudi();
    void show();
    int   exec();

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // DIALOGVOCABOLARIO_H
