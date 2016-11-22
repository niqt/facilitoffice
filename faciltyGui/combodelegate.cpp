#include "combodelegate.h"
#include <QtGui>
#include <QtWidgets/QComboBox>
#include <QDebug>

ComboDelegate::ComboDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

QWidget *ComboDelegate::createEditor(QWidget *parent,
                                     const QStyleOptionViewItem & /* option */,
                                     const QModelIndex &index) const
{


    if (index.column() == 1)
    {
        QComboBox *comboBox = new QComboBox(parent);
        for(int i = 0; i < files.count(); i++)
        {
            comboBox->addItem(files.at(i));
            qDebug() << files.at(i) << endl;
        }
        connect(comboBox, SIGNAL(activated(int)), this, SLOT(emitCommitData()));

        return comboBox;
    }



}

void ComboDelegate::setEditorData(QWidget *editor,
                                  const QModelIndex &index) const
{

    if (index.column() == 1)
    {
        QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
        if (!comboBox)
            return;

        int pos = comboBox->findText(index.model()->data(index).toString(),
                                     Qt::MatchExactly);
        comboBox->setCurrentIndex(pos);
    }
}

void ComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                 const QModelIndex &index) const
{

    if (index.column() == 1)
    {
        QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
        if (!comboBox)
            return;

        model->setData(index, comboBox->currentText());
    }
}

void ComboDelegate::emitCommitData()
{
    emit commitData(qobject_cast<QWidget *>(sender()));
}

void ComboDelegate::setItems(QStringList files)
{
    this->files = files;
}
