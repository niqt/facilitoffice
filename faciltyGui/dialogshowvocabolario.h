#ifndef DIALOGSHOWVOCABOLARIO_H
#define DIALOGSHOWVOCABOLARIO_H

#include <QtWidgets/QDialog>
#include "db.h"
#include <QCloseEvent>

namespace Ui
{
    class VocabolarioDialogClass;
}

class DialogShowVocabolario : public QDialog
{
    Q_OBJECT
    private:
        Ui::VocabolarioDialogClass *ui;
        Db *db;
    public:
        DialogShowVocabolario(QWidget *parent = 0);
        ~DialogShowVocabolario() {;}
        void setText(QString word);
    public slots:
        void show(QString word);
        void hide();
        void leggi();
        void upper();
    protected:
        void closeEvent(QCloseEvent *event);
};

#endif // DIALOGSHOWVOCABOLARIO_H
