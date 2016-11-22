#include "db.h"
#include <QDir>
#include <QDebug>
#include <QPixmap>

Db::Db(QString name)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::homePath() + QDir::separator() + name);
    db.open();
}

bool Db::isExist()
{
    if (!db.open())
        return false;
    db.close();
    return true;
}

bool Db::create()
{
    //if(!isExist())
    {

        QSqlQuery query;

        query.exec("create table IF NOT EXISTS termini (termine varchar(20) primary key, descrizione varchar(100), img LONGBLOB )");
        //db.close();
        return true;
    }
    return false;
}

bool Db::open()
{
    return db.open();
}

void Db::close()
{
    db.close();
}



void Db::insert(QString name, QString definition, QVariant vimg)
{
    QSqlQuery query;
    QVariant vname(name);
    QVariant vdefinition (definition);

    query.prepare("select count(*)  from termini where termine = ?");
    query.addBindValue(vname);
    query.exec();
    query.next();

    if(query.value(0).toInt() > 0)
    {

        query.prepare("update termini set descrizione = ? , img = ? where termine = ?");
        query.addBindValue(vdefinition);
        query.addBindValue(vimg);
        query.addBindValue(vname);
        if(query.exec())
            qDebug() << "UPDATE OK\n";
        else
            qDebug() << query.lastError() << endl;
    }
    else
    {
        query.prepare("insert into termini values(?, ?, ?)");
        query.addBindValue(vname);
        query.addBindValue(vdefinition);
        query.addBindValue(vimg);
        query.exec();
        //qDebug() << "INSERT " << query.lastError() << endl;
    }

}

void Db::erase(QString name)
{
    QSqlQuery query;
    QVariant vname(name);



    query.prepare("delete from termini where termine = ?");
    query.addBindValue(vname);
    query.exec();
}

bool Db::getInfo(QString termine, QString &descrizione, QPixmap &pixmap)
{
    QSqlQuery query;
    QVariant vtermine(termine);
    query.prepare("select *  from termini where termine = ?");
    query.addBindValue(vtermine);
    query.exec();
    if(query.next())
    {
        descrizione = query.value(1).toString();
        QByteArray bytes = query.value(2).toByteArray();

        pixmap.loadFromData(bytes);

        return true;
    }
    return false;
}
