#include "filedelagate.h"
#include <QDir>

FileDelagate::FileDelagate(QObject *parent) : QStyledItemDelegate(parent)
{
}




void FileDelagate::paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{

     if(index.column() == 1)
     {
         /*QByteArray value = index.model()->data(index, Qt::EditRole).toByteArray();
         QPixmap pixmap;

         pixmap.loadFromData(value);
         pixmap = pixmap.scaled(100, 100);

         painter->drawPixmap(option.rect, pixmap);*/

        QStyledItemDelegate::paint(painter, option, index);

     }
     else
       QStyledItemDelegate::paint(painter, option, index);


}

QSize FileDelagate::sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const
{

     if(index.column() == 2)
     {
         QSize size(100,100);
         return size;
     }
     else
       return QStyledItemDelegate::sizeHint( option, index );
}

QString FileDelagate::displayText ( const QVariant & value, const QLocale & locale ) const
{
    QString s = value.toString();
    if(s.contains(QDir::separator()))
        s = s.remove(0, s.lastIndexOf(QDir::separator()) + 1);
    return s.trimmed();
}
