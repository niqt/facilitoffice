#include "dialogvocabolario.h"
#include "ui_dialogvocabolario.h"
#include <QtWidgets/QFileDialog>

#include <QByteArray>
#include <QDebug>
#include <QBuffer>

#include <QtWidgets/QStyledItemDelegate>
#include "imagedelegate.h"

DialogVocabolario::DialogVocabolario(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::DialogVocabolario)
{
    m_ui->setupUi(this);
    modify = false;
    currentItem = -1;
    db = new Db("facdb");
    //if(!db->isExist())
        db->create();
    //db->open();

    model = new QSqlTableModel();
    model->setTable("termini");







    model->setHeaderData(0, Qt::Horizontal, tr("Termine"));
    model->setHeaderData(1, Qt::Horizontal, tr("Definizione"));
    model->setHeaderData(2, Qt::Horizontal, tr("Immagine"));


    model->select();



    m_ui->tableView->setModel(model);
    m_ui->tableView->setItemDelegate(new ImageDelegate(m_ui->tableView));

    m_ui->tableView->setWindowTitle("Vocabolario");
    m_ui->tableView->resizeColumnsToContents();
    m_ui->tableView->resizeRowsToContents();
    m_ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    m_ui->listView->setModel(model);
    m_ui->listView->setModelColumn(0);


}

DialogVocabolario::~DialogVocabolario()
{
    delete m_ui;
}

void DialogVocabolario::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void DialogVocabolario::immagine()
{
     QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                 QDir::homePath(),
                                                 tr("Images (*.png *.xpm *.jpg *gif)"));

     if(fileName.size() > 0)
     {

        img.load(fileName);
        img = img.scaled(245, 305);
        m_ui->labelImg->setPixmap(img);
        modify = true;
    }
}

void DialogVocabolario::save()
{

    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);

    img.save(&buffer, "JPG");

    QVariant v(bytes);
    db->insert(m_ui->lineEdit->text(), m_ui->textEdit->toPlainText(),v );
    model->select();
    /*m_ui->tableView->setModel(model);
    m_ui->listView->setModel(model);
    m_ui->listView->setModelColumn(0);*/
    m_ui->tableView->resizeColumnsToContents();
    m_ui->tableView->resizeRowsToContents();


}

void DialogVocabolario::elimina()
{
    QModelIndex index = m_ui->listView->currentIndex();
    QModelIndex i;
    QModelIndex s;

    db->erase((model->data(index)).toString());




    model->removeRows(index.row(), 1, i);

    this->nuovo();
    m_ui->tableView->resizeColumnsToContents();
    m_ui->tableView->resizeRowsToContents();



    if(model->rowCount(s) == 0)
        m_ui->pushButtonElimina->setEnabled(false);
}


void DialogVocabolario::nuovo()
{
    QPixmap pixmap;
    m_ui->lineEdit->setText("");

    m_ui->textEdit->clear();
    m_ui->labelImg->setText("");
    m_ui->labelImg->setPixmap(pixmap);
}

void DialogVocabolario::select(QModelIndex index)
{
    QByteArray bytes = (model->data(index.sibling(index.row(), 2))).toByteArray();
    QPixmap pixmap;
    pixmap.loadFromData(bytes);
    pixmap = pixmap.scaled(245, 305);
    m_ui->labelImg->setPixmap(pixmap);

    m_ui->lineEdit->setText((model->data(index)).toString());
    m_ui->textEdit->setText((model->data(index.sibling(index.row(), 1))).toString());
    m_ui->pushButtonElimina->setEnabled(true);
}


void DialogVocabolario::show()
{

    m_ui->tabWidget->setCurrentIndex(0);
    QDialog::show();
}


int DialogVocabolario::exec()
{
    m_ui->tabWidget->setCurrentIndex(0);
    QDialog::exec();
}

void DialogVocabolario::chiudi()
{
    QDialog::setVisible(false);
}

void DialogVocabolario::closeEvent(QCloseEvent *event)
{

    event->ignore();
    QDialog::setVisible(false);

}
