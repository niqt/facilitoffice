#include "dialogmodelli.h"
#include "ui_dialogmodelli.h"
#include "dialogmodello.h"

#include "combodelegate.h"
#include <QDebug>
#include <QStringList>
#include <QtWidgets/QComboBox>

DialogModelli::DialogModelli(QWidget *parent)
    : QDialog(parent), ui(new Ui::DialogModelli)
{
    ui->setupUi(this);
    QModelIndex index;
    delegate = new  FileDelagate(this);

    modelli = new Modelli(QDir::homePath() + "/Documenti/facilitoffice/");

    QStringList h;
    h << "Modello" << "Descrizione";
     fileModello = new FileModel(this/*, h*/);
    fileModello->setHeaderData(0, Qt::Horizontal, QObject::tr("Modello"),  Qt::DisplayRole);
    fileModello->setHeaderData(1, Qt::Horizontal, QObject::tr("Descrizione"),  Qt::DisplayRole);
    fileModello->setInfo(modelli->getModello());
    ui->tableView->setModel(fileModello);

    ui->tableView->setItemDelegate(delegate);

    ui->tableView->verticalHeader()->setVisible(false);

    ui->tableView->setColumnWidth(0, 300);
    ui->tableView->setColumnWidth(1, 300);

    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->resizeColumnsToContents();
}

DialogModelli::~DialogModelli()
{
    delete ui;

    delete fileModello;
}

QString DialogModelli::modello(QStringList quaderni, QStringList modelliNames, QStringList &selezionati, QDir baseDir)
{
    QString d;
    QStringList head, files;
    QString fileName;
    QStringList h;

    nQuaderni = quaderni.size();
    _quaderni = quaderni;
    _baseDir = baseDir;



    delete modelli;
    modelli = new Modelli(_baseDir.absolutePath() + "/facilitoffice/");


    h << "Modello" << "Descrizione";

    fileModello = new FileModel(this/*, h*/);
    fileModello->setHeaderData(0, Qt::Horizontal, QObject::tr("Modello"),  Qt::DisplayRole);
    fileModello->setHeaderData(1, Qt::Horizontal, QObject::tr("Descrizione"),  Qt::DisplayRole);
    fileModello->setInfo(modelli->getModello());
    ui->tableView->setModel(fileModello);

    ui->tableView->setItemDelegate(delegate);

    ui->tableView->verticalHeader()->setVisible(false);

    ui->tableView->setColumnWidth(0, 300);
    ui->tableView->setColumnWidth(1, 300);


    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->resizeColumnsToContents();

    this->modelli->loadModello("elenco");


    for (int i = 0; i < this->modelli->getModello().count(); i++) {
       fileName = this->modelli->getModello().at(i).at(0);
       fileName = fileName.remove(0, fileName.lastIndexOf(QDir::separator()) + 1);
       fileName.trimmed();
       files << fileName;
       //files << row.at(1);

    }

    ui->tableWidget->clear();

    ui->tabWidget->setCurrentIndex(0);

    head << "Quaderno" << "Modello";

    //qDebug() << quaderni.count() << endl;

    ComboDelegate *comboDelegate = new ComboDelegate(this);

    comboDelegate->setItems(files);
    ui->tableWidget->setItemDelegate(comboDelegate);



    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(10);
    for(int i = 0; i < 10; i++)
    {
        if (i <= quaderni.count() - 1) {
           QTableWidgetItem *item0 = new QTableWidgetItem(quaderni.at(i));
           ui->tableWidget->setItem(i, 0, item0);
        }

        QTableWidgetItem *item1 = new QTableWidgetItem();

        ui->tableWidget->setItem(i, 1, item1);
        ui->tableWidget->openPersistentEditor(item1);
    }
    ui->tableWidget->setHorizontalHeaderLabels(head);
    ui->tableWidget->setColumnWidth(0, 200);
    ui->tableWidget->setColumnWidth(1, 300);
    ui->tableWidget->verticalHeader()->setVisible(false);

    //this->modelli->loadModello("elenco");


    fileModello->setInfo(this->modelli->getModello());

    QDialog::exec();

    QTableWidgetItem *item;

    selezionati.clear();

    for(int i = 0; i < 10; i++)
    {

        item =  ui->tableWidget->item(i, 1);

        selezionati.append(item->text());
        //qDebug() << i << " item->text() " << item->text() << endl;
        // qDebug() << i << " MODELLO " << selezionati.at(i) << endl;
    }

    /*for(int i = 0; i < 10; i++)
    {




        qDebug() << i << " modello MODELLO " << selezionati.at(i) << endl;

    }*/
    
    return d;

}

void DialogModelli::nuovo()
{
    DialogModello modello;
    QString fileName;
    QStringList files, head;
    QStringList modelInfo = modello.getModello();

    if(modelInfo.at(0) != "" && modelInfo.at(1) != "") {
        modelli->setModello(modelInfo.at(0), modelInfo.at(1));

        fileModello->setInfo(modelli->getModello());
        fileName =  modelInfo.at(0);
        fileName = fileName.remove(0, fileName.lastIndexOf(QDir::separator()) + 1);
        QFile::copy(modelInfo.at(0), _baseDir.absolutePath() + "/facilitoffice/modelli/" + fileName);

        for (int i = 0; i < this->modelli->getModello().size(); i++) {
           fileName = this->modelli->getModello().at(i).at(0);
           //if (fileName)
           fileName = fileName.remove(0, fileName.lastIndexOf(QDir::separator()) + 1);
           fileName.trimmed();
           files << fileName;

           qDebug() << "FILE " << fileName << endl;
        }

        ui->tableWidget->clear();

        ui->tabWidget->setCurrentIndex(0);

        head << "Quaderno" << "Modello";



        ComboDelegate *comboDelegate = new ComboDelegate(this);

        comboDelegate->setItems(files);
        ui->tableWidget->setItemDelegate(comboDelegate);




        ui->tableWidget->setColumnCount(2);
        ui->tableWidget->setRowCount(10);
        for(int i = 0; i < 10; i++)
        {
            if (i <= _quaderni.count() - 1) {
               QTableWidgetItem *item0 = new QTableWidgetItem(_quaderni.at(i));
               ui->tableWidget->setItem(i, 0, item0);
            }

            QTableWidgetItem *item1 = new QTableWidgetItem();

            ui->tableWidget->setItem(i, 1, item1);
            ui->tableWidget->openPersistentEditor(item1);
        }
        ui->tableWidget->setHorizontalHeaderLabels(head);
        ui->tableWidget->setColumnWidth(0, 200);
        ui->tableWidget->setColumnWidth(1, 300);
        ui->tableWidget->verticalHeader()->setVisible(false);
    }
}


void DialogModelli::tabChanged(int index)
{
    ui->pushButton_elimina->setEnabled((index == 0));
    ui->pushButton_nuovo->setEnabled((index == 0));

   if (index == 1) {
        QStringList head, files;
        QString fileName;

 //this->modelli->getModello().clear();
        /*for (int i = 0; i < this->modelli->getModello().size(); i++) {
           fileName.setNum(this->modelli->getModello().at(i).size());
           fileName = fileName.remove(0, fileName.lastIndexOf(QDir::separator()) + 1);
           fileName.trimmed();
           files << fileName;
           
           qDebug() << "FILE " << fileName << endl;
           }*/
/*
        ui->tableWidget->clear();

        ui->tabWidget->setCurrentIndex(0);

        head << "Quaderno" << "Modello";



        ComboDelegate *comboDelegate = new ComboDelegate(this);

        comboDelegate->setItems(files);
        ui->tableWidget->setItemDelegate(comboDelegate);




        ui->tableWidget->setColumnCount(2);
        ui->tableWidget->setRowCount(10);
        for(int i = 0; i < 10; i++)
        {
            if (i <= _quaderni.count() - 1) {
               QTableWidgetItem *item0 = new QTableWidgetItem(_quaderni.at(i));
               ui->tableWidget->setItem(i, 0, item0);
            }

            QTableWidgetItem *item1 = new QTableWidgetItem();

            ui->tableWidget->setItem(i, 1, item1);
            ui->tableWidget->openPersistentEditor(item1);
        }
        ui->tableWidget->setHorizontalHeaderLabels(head);
        ui->tableWidget->setColumnWidth(0, 200);
        ui->tableWidget->setColumnWidth(1, 300);
        ui->tableWidget->verticalHeader()->setVisible(false);
        */
    }
}

void DialogModelli::elimina()
{
   QModelIndex index = ui->tableView->currentIndex();
   if (index.row() >= 0) {
       modelli->remove(index.row());
       fileModello->setInfo(modelli->getModello());
       QString fileName;
       QStringList files, head;
       for (int i = 0; i < this->modelli->getModello().size(); i++) {
          fileName = this->modelli->getModello().at(i).at(0);
          //if (fileName)
          fileName = fileName.remove(0, fileName.lastIndexOf(QDir::separator()) + 1);
          fileName.trimmed();
          files << fileName;

          qDebug() << "FILE " << fileName << endl;
        }

       ui->tableWidget->clear();

       ui->tabWidget->setCurrentIndex(0);

       head << "Quaderno" << "Modello";



       ComboDelegate *comboDelegate = new ComboDelegate(this);

       comboDelegate->setItems(files);
       ui->tableWidget->setItemDelegate(comboDelegate);




       ui->tableWidget->setColumnCount(2);
       ui->tableWidget->setRowCount(10);
       for(int i = 0; i < 10; i++)
       {
           if (i <= _quaderni.count() - 1) {
              QTableWidgetItem *item0 = new QTableWidgetItem(_quaderni.at(i));
              ui->tableWidget->setItem(i, 0, item0);
           }

           QTableWidgetItem *item1 = new QTableWidgetItem();

           ui->tableWidget->setItem(i, 1, item1);
           ui->tableWidget->openPersistentEditor(item1);
       }
       ui->tableWidget->setHorizontalHeaderLabels(head);
       ui->tableWidget->setColumnWidth(0, 200);
       ui->tableWidget->setColumnWidth(1, 300);
       ui->tableWidget->verticalHeader()->setVisible(false);

   }
}
