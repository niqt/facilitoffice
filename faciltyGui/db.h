#ifndef DB_H
#define DB_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

class Db
{
private:
    QSqlDatabase db;
public:
    Db(QString name);
    bool isExist();
    bool create();
    bool open();
    void close();
    void insert(QString name, QString definition, QVariant vimg);
    void erase(QString name);
    bool getInfo(QString termine, QString &descrizione, QPixmap &pixmap);
    //bool get(QString name
};


#endif // DB_H
