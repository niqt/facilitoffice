#include "filemodel.h"

#include <QSize>
#include <QDebug>

 FileModel::FileModel(QObject *parent/*, QStringList header*/)
     : QAbstractTableModel(parent)
 {
    //_header = header;
 }

 void FileModel::setInfo(const QList<QList<QByteArray> > &l)
 {
     listModel = l;
     emit layoutChanged();
 }

 int FileModel::rowCount(const QModelIndex & /* parent */) const
 {
     return listModel.count();
 }

 int FileModel::columnCount(const QModelIndex & /* parent */) const
 {
     if(listModel.count() == 0)
         return 0;
     QList<QByteArray> row = listModel.at(0);
     return row.count();
 }

 QVariant FileModel::data(const QModelIndex &index, int role) const
 {

     if (listModel.count() == 0 || (!index.isValid() || role != Qt::DisplayRole))
         return QVariant();

     QList<QByteArray> row = listModel.at(index.row());
     return QVariant(row.at(index.column()));

 }


 QVariant FileModel::headerData ( int section, Qt::Orientation orientation, int role ) const
 {

     if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {

        return QVariant(_header.at(section));
    }
    return QVariant();


 }

 bool FileModel::setHeaderData ( int section, Qt::Orientation orientation, const QVariant & value, int role  )
 {
     if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        if(section > (_header.count() - 1)) {
            for(int i = _header.count(); i <= section; i++)
                _header.append("");
        }
        _header.replace(section, value.toString());

        emit headerDataChanged( orientation, section, section );
        return true;
    }
    return false;
 }

