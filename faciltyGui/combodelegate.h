#ifndef COMBODELEGATE_H
#define COMBODELEGATE_H

#include <QtWidgets/QItemDelegate>

class ComboDelegate : public QItemDelegate
{
public:
    ComboDelegate(QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void setItems(QStringList files);

private slots:
    void emitCommitData();
private:
    QStringList files;
};

#endif // COMBODELEGATE_H
