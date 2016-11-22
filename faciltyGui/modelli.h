#ifndef MODELLI_H
#define MODELLI_H

#include <QFile>
#include <QList>
#include <QDir>

/*typedef struct modello
{
    QString file;
    QString desc;
}Modello_s;
*/

class Modelli
{
private:
    QFile elenco;
    QList<QList<QByteArray> > modello;
    QDir dir;
public:
    Modelli(QString dir);
    ~Modelli();
    void setModello(QString file, QString descrizione);
    void loadModello(QString file);
    QList<QList<QByteArray> > getModello();
    void remove(int index);
};

#endif // MODELLI_H
