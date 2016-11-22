#include "modelli.h"
#include <QTextStream>
#include <QDebug>
Modelli::Modelli(QString dir)
{
    this->dir.setPath(dir);
    elenco.setFileName(this->dir.absolutePath() + QDir::separator() + "elenco");
    elenco.open(QIODevice::ReadWrite | QIODevice::Text);
    loadModello("elenco");
}

void Modelli::setModello(QString file, QString descrizione)
{
    if(elenco.error() == QFile::NoError)
    {
        QList<QByteArray> dum;
        QTextStream out(&elenco);

        dum.append(file.toStdString().c_str());
        dum.append(descrizione.toStdString().c_str());
        modello.append(dum);
        while (!elenco.atEnd())
        {
            QByteArray line = elenco.readLine();
        }

        out << file << "," << descrizione << "\n";
    }
}

void Modelli::loadModello(QString file)
{

    if(elenco.error() == QFile::NoError)
    {
         modello.clear();

        //qDebug() << "QUIIII\n";
         elenco.seek(0);
        while (!elenco.atEnd())
        {
            //qDebug() << "leggi";
            QByteArray line = elenco.readLine();

            line.remove(line.size() - 1, 1);
            QList<QByteArray> dum = line.split(',');
            modello.append(dum);

        }
     }
}


QList<QList<QByteArray> > Modelli::getModello()
{
    return modello;
}


void Modelli::remove(int index)
{
    if (index >= 0 && index < modello.size()) {
        modello.removeAt(index);
        elenco.close();
        QFile::remove(elenco.fileName());
        elenco.open(QIODevice::ReadWrite | QIODevice::Text);

        QTextStream out(&elenco);
        for (int i = 0; i < modello.size(); i++) {
            out << modello.at(i).at(0) << "," << modello.at(i).at(1) << "\n";
        }
    }
}

Modelli::~Modelli()
{

    elenco.close();
}
