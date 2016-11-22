#include "dialogpagina.h"
#include "ui_dialogpagina.h"
#include <QSqlQuery>
#include <QDate>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QInputDialog>

DialogPagina::DialogPagina(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPagina)
{
    ui->setupUi(this);
    mb =  new QMenuBar(this);
    mb->setFixedWidth(this->width());


    mb->addAction(ui->actionChiudi);
    mb->addAction(ui->actionApri);
    mb->addAction(ui->actionInserisci);
    mb->addAction(ui->actionEliminazione);
    model = new QSqlQueryModel();

    model->setQuery("select * from pagine");



    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Quaderno"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nome"));
    model->setHeaderData(3, Qt::Horizontal, tr("Day"));
    model->setHeaderData(4, Qt::Horizontal, tr("Descrizione"));

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(1, true);
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->resizeColumnsToContents();

    _selected = false;
}


void DialogPagina::nuova()
{
    int nrecord;
    QSqlQuery query;
    QString name;
    QString next;
    int id;
    bool ok;

    _descrizione = QInputDialog::getText(this, tr("Inserisci la descrizione"),
                                              tr("Descrizione:"), QLineEdit::Normal,
                                              "", &ok);


    query.prepare("select count(*)  from pagine where day=?");
    query.bindValue(0, QVariant(QDate::currentDate()));
    query.exec();
    while (query.next()) {
        nrecord = query.value(0).toInt() + 1;

    }


    next.setNum(nrecord);

    query.prepare("select max(id) from pagine");
    query.exec();
    while (query.next()) {
        id = query.value(0).toInt() + 1;

    }


    name = "quaderno_" + QDate::currentDate().toString("dd.MM.yyyy") + "_" + next;



    query.prepare("INSERT INTO pagine (id, quaderno, nome, day, descrizione) VALUES (?, ?, ?, ?, ?)");
    query.bindValue(0, id);
    query.bindValue(1, _quaderno.toInt());
    query.bindValue(2, name);
    query.bindValue(3, QDate::currentDate());
    query.bindValue(4, _descrizione);
    query.exec();

    // CREATE FILE PAGE

    _pagina =  _baseDir.absolutePath() + "/facilitoffice/quaderni/" + _quaderno + "/" + name;

    QFile::copy(_baseDir.absolutePath() + "/facilitoffice/modelli/" + _fileNameModello, _pagina);


    //qDebug() << "ORIG " << _baseDir.absolutePath() + "/facilitoffice/modelli/" + _fileNameModello << " DEST " << _pagina << endl;


    model->clear();
    model->setQuery("select * from pagine where quaderno=" + _quaderno);

    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Quaderno"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nome"));
    model->setHeaderData(3, Qt::Horizontal, tr("Day"));
    model->setHeaderData(4, Qt::Horizontal, tr("Descrizione"));

    ui->tableView->setModel(model);

    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(1, true);
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->resizeColumnsToContents();

}

void DialogPagina::inserisci()
{
    QSqlQuery query;
    int id = -1;
    bool ok;

    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Inserisci modello"), QDir::homePath(), tr("OO Files (*.odt)"));

    //qDebug() << "FILE " << fileName << endl;
    QString name = fileName;
    name = name.remove(0, fileName.lastIndexOf(QDir::separator()) + 1);
    name.trimmed();


    _pagina =  _baseDir.absolutePath() + "/facilitoffice/quaderni/" + _quaderno + "/" + name;

    QFile::copy(fileName, _pagina);



    //qDebug() << "S " << fileName << " DESt" << _pagina << endl;

    query.prepare("select max(id) from pagine");
    query.exec();
    while (query.next()) {
        id = query.value(0).toInt() + 1;

    }

    QSqlError er = query.lastError();
    qDebug() << "ERR " << er.text() << endl;

    _descrizione = QInputDialog::getText(this, tr("Inserisci la descrizione"),
                                              tr("Descrizione:"), QLineEdit::Normal,
                                              "", &ok);


    query.prepare("INSERT INTO pagine (id, quaderno, nome, day, descrizione) VALUES (?, ?, ?, ?, ?)");
    query.bindValue(0, id);
    query.bindValue(1, _quaderno.toInt());
    query.bindValue(2, name);
    query.bindValue(3, QDate::currentDate());
    query.bindValue(4, _descrizione);
    query.exec();




    model->clear();
    model->setQuery("select * from pagine where quaderno=" + _quaderno);

    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Quaderno"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nome"));
    model->setHeaderData(3, Qt::Horizontal, tr("Day"));
    model->setHeaderData(4, Qt::Horizontal, tr("Descrizione"));

    ui->tableView->setModel(model);

    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(1, true);
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


}

void DialogPagina::selectedItem(QModelIndex index)
{
    _selected = true;

}

void DialogPagina::elimina()
{
    QModelIndex index = ui->tableView->currentIndex();
    QSqlRecord record;
    QSqlQuery query;
    if (index.isValid() && _selected) {
        record = model->record(index.row());

        QFile::remove(_baseDir.absolutePath() + "/facilitoffice/quaderni/" + _quaderno + "/" + record.value("nome").toString());

        query.prepare("delete  from pagine where id=?");
        query.bindValue(0, QVariant(record.value("id").toInt()));
        query.exec();

        model->setQuery("select * from pagine where quaderno=" + _quaderno);
        _selected = false;
    }

}

void DialogPagina::pagina(QString fileNameModello, QString quaderno, QDir baseDir, QString &pathPagina, bool &ok)
{
    model->setQuery("select * from pagine where quaderno=" + quaderno);



    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Quaderno"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nome"));
    model->setHeaderData(3, Qt::Horizontal, tr("Day"));
    model->setHeaderData(4, Qt::Horizontal, tr("Descrizione"));

    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(1, true);
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->resizeColumnsToContents();

    _selected = false;

    _baseDir = baseDir;
    _quaderno = quaderno;
    _fileNameModello = fileNameModello;
    _pagina = "";

    if (fileNameModello.size() == 0)
        ui->pushButtonNuova->setEnabled(false);

    this->exec();
    pathPagina = _pagina;
    ok = (_pagina.size() > 0);
}

void DialogPagina::apri()
{
    QModelIndex index = ui->tableView->currentIndex();
    QSqlRecord record;
    QSqlQuery query;
    if (index.isValid() && _selected) {
        record = model->record(index.row());

        _pagina = _baseDir.absolutePath() + "/facilitoffice/quaderni/" + _quaderno + "/" + record.value("nome").toString();

        emit QDialog::accept();

    }

}

DialogPagina::~DialogPagina()
{
    delete ui;
    delete mb;
    delete model;
}

void DialogPagina::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
