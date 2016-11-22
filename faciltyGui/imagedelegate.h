#ifndef IMAGEDELEGATE_H
#define IMAGEDELEGATE_H



 #include <QtWidgets/QStyledItemDelegate>

 #include <QtWidgets/QItemDelegate>
 #include <QModelIndex>
 #include <QObject>
 #include <QSize>


 class ImageDelegate : public QStyledItemDelegate
 {
     Q_OBJECT

 public:
     ImageDelegate(QObject *parent = 0);

     /*QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const;

     void setEditorData(QWidget *editor, const QModelIndex &index) const;
     void setModelData(QWidget *editor, QAbstractItemModel *model,
                       const QModelIndex &index) const;

     void updateEditorGeometry(QWidget *editor,
         const QStyleOptionViewItem &option, const QModelIndex &index) const;
*/
     void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
     QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const;
 };


#endif // IMAGEDELEGATE_H
