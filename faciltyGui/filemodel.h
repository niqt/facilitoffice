#ifndef FILEMODEL_H
#define FILEMODEL_H

#include <QAbstractTableModel>
#include <QStringList>

class FileModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    FileModel(QObject *parent/*, QStringList header*/);
    void setInfo(const QList<QList<QByteArray> > &l);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setHeaderData( int section, Qt::Orientation orientation, const QVariant & value, int role = Qt::EditRole );
private:
     QList<QList<QByteArray> > listModel;
     QStringList _header;
};

#endif // FILEMODEL_H

