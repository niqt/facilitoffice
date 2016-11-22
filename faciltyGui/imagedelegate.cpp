#include "imagedelegate.h"

#include <QtGui>


ImageDelegate::ImageDelegate(QObject *parent)
     : QStyledItemDelegate(parent)
 {
    
 }

#if 0
 QWidget *ImageDelegate::createEditor(QWidget *parent,
     const QStyleOptionViewItem &/* option */,
     const QModelIndex &/* index */) const
 {
     QLabel *editor = new QLabel(parent);

       qDebug() << "CREO\n";
     return editor;
 }

 void ImageDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
 {
     QString value = index.model()->data(index, Qt::EditRole).toString();
     qDebug() << "SET\n";
     QLabel *label = static_cast<QLabel*>(editor);
     qDebug() << "N C " << index.column() << endl;
     if(index.column() == 2)
     {
         label->setText("pippo");
     }
     else
        label->setText(value);
 }

 void ImageDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
 {
     QLabel *label = static_cast<QLabel*>(editor);
     qDebug() << "MODEL\n";
     QString value = label->text();

     model->setData(index, value, Qt::EditRole);
 }

 void ImageDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
 {
     qDebug() << "GEOMETRY\n";
     editor->setGeometry(option.rect);
 }
#endif
 void ImageDelegate::paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
 {

     if(index.column() == 2)
     {
         QByteArray value = index.model()->data(index, Qt::EditRole).toByteArray();
         QPixmap pixmap;

         pixmap.loadFromData(value);
         pixmap = pixmap.scaled(100, 100);

         painter->drawPixmap(option.rect, pixmap);



     }
     else
       QStyledItemDelegate::paint(painter, option, index);


 }

 QSize ImageDelegate::sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const
 {

     if(index.column() == 2)
     {
         QSize size(100,100);
         return size;
     }
     else
       return QStyledItemDelegate::sizeHint( option, index );
 }
