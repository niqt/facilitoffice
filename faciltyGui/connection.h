
#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtWidgets/QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDir>

/*
    This file defines a helper function to open a connection to an
    in-memory SQLITE database and to create a test table.

    If you want to use another database, simply modify the code
    below. All the examples in this directory use this function to
    connect to a database.
*/


static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");



    db.setDatabaseName(QDir::homePath() + QDir::separator() + "facidb");



    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "This software needs SQLite support. Please"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }



    QSqlQuery query;
    query.exec("create table IF NOT EXISTS pagine (id int primary key,  quaderno int, nome varchar(50), day DATE, descrizione varchar(30))");

    return true;
}



#endif // CONNECTION_H
