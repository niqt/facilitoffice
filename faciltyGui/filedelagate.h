#ifndef FILEDELAGATE_H
#define FILEDELAGATE_H


#include <QtWidgets/QItemDelegate>
#include <QtWidgets/QStyledItemDelegate>

class FileDelagate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    FileDelagate(QObject *parent = 0);
    void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    QString displayText ( const QVariant & value, const QLocale & locale ) const;
};

#endif // FILEDELAGATE_H
