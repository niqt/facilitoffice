#include "dialogquaderni.h"
#include "ui_dialogquaderni.h"
#include <QtWidgets/QColorDialog>
#include "dialogpagina.h"
#include <QSqlDatabase>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include "connection.h"
DialogQuaderni::DialogQuaderni(QWidget *parent)
    : QDialog(parent), ui(new Ui::DialogQuaderni)
{
    ui->setupUi(this);
    mb =  new QMenuBar(this);
    mb->setFixedWidth(this->width());
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    /*ui->pushButton_impostazioni->setVisible(false);
    ui->pushButton_etichetta->setVisible(false);
    ui->pushButton_modelli->setVisible(false);
    ui->pushButton_chiudi->setVisible(false);*/
    createActions();
    createMenu();
    _maiuscolo = false;
    _mostraModelli = true;

createConnection();

/*
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");



    db.setDatabaseName(QDir::homePath() + QDir::separator() + "faci");

    QSqlQuery query;

    if (db.open()) {
        query.exec("create table IF NOT EXISTS pagine (id int primary key, int quaderno, nome varchar(50), day DATE, descrizione varchar(30))");
        if(query.isActive())
            //qDebug() << "QUERY OK\n";
        QSqlError e = query.lastError();
        //qDebug() << "OPEn\n" << e.text();
        db.close();
    }
    else
        //qDebug() << "NON OPEn\n";
*/
    QDir dir;
    //QString );

    dir.setPath(QDir::homePath() + "/Documenti/facilitoffice");

    if (dir.exists() == false) {
        dir.mkdir(dir.absolutePath());
    }


    dir.setPath(QDir::homePath() + "/Documenti/facilitoffice/modelli");

    if (dir.exists() == false)
        dir.mkdir(dir.absolutePath());


    dir.setPath(QDir::homePath() + "/Documenti/facilitoffice/quaderni");

    if (dir.exists() == false)
        dir.mkdir(dir.absolutePath());

    QString quaderno;

    for (int i = 1; i < 11; i++) {
        quaderno.setNum(i);
        dir.setPath(QDir::homePath() + "/Documenti/facilitoffice/quaderni/" + quaderno);

        if (dir.exists() == false)
            dir.mkdir(dir.absolutePath());

    }

    _baseDir.setPath(QDir::homePath() + "/Documenti/");
    if (modelliFiles.size() == 0)
        for (int i = 0; i < 10; i++)
            modelliFiles << "";

    _numeroQuaderni = 10;
}


void DialogQuaderni::q1()
{

    if(hasName(ui->pushButton_1))
    {
        DialogPagina p;
        bool ok;



        p.pagina(modelliFiles.at(0), "1", _baseDir, _pagina, ok);


        if (ok == false)
            _pagina = "";
        else {
            this->setVisible(false);
            emit loadPagina(_pagina);
        }
    }
    else
        ui->pushButton_1->setText(ui->pushButton_1->text() + "\n" + ((_maiuscolo)?dialogEtichetta.etichetta("1").toUpper():dialogEtichetta.etichetta("1")));
}

void DialogQuaderni::q2()
{
    if(hasName(ui->pushButton_2))
    {
        DialogPagina p;
        bool ok;

        p.pagina(modelliFiles.at(0), "2", _baseDir, _pagina, ok);

        if (ok == false)
            _pagina = "";
        else
            this->setVisible(false);
    }
    else
        ui->pushButton_2->setText(ui->pushButton_2->text() + "\n" + dialogEtichetta.etichetta("2"));
}

void DialogQuaderni::q3()
{
    if(hasName(ui->pushButton_3))
    {
        DialogPagina p;
        bool ok;

        p.pagina(modelliFiles.at(0), "3", _baseDir, _pagina, ok);

        if (ok == false)
            _pagina = "";
        else
            this->setVisible(false);
    }
    else
        ui->pushButton_3->setText(ui->pushButton_3->text() + "\n" + dialogEtichetta.etichetta("3"));
}

void DialogQuaderni::q4()
{
    if(hasName(ui->pushButton_4))
    {
        DialogPagina p;
        bool ok;

        p.pagina(modelliFiles.at(0), "4", _baseDir, _pagina, ok);

        if (ok == false)
            _pagina = "";
        else
            this->setVisible(false);
    }
    else
        ui->pushButton_4->setText(ui->pushButton_4->text() + "\n" + dialogEtichetta.etichetta("4"));
}

void DialogQuaderni::q5()
{
    if(hasName(ui->pushButton_5))
    {
        DialogPagina p;
        bool ok;

        p.pagina(modelliFiles.at(0), "5", _baseDir, _pagina, ok);

        if (ok == false)
            _pagina = "";
        else
            this->setVisible(false);
    }
    else
        ui->pushButton_5->setText(ui->pushButton_5->text() + "\n" + dialogEtichetta.etichetta("5"));
}
void DialogQuaderni::q6()
{
    if(hasName(ui->pushButton_6))
    {
        DialogPagina p;
        bool ok;

        p.pagina(modelliFiles.at(0), "6", _baseDir, _pagina, ok);

        if (ok == false)
            _pagina = "";
        else
            this->setVisible(false);
    }
    else
        ui->pushButton_6->setText(ui->pushButton_6->text() + "\n" + dialogEtichetta.etichetta("6"));
}
void DialogQuaderni::q7()
{
    if(hasName(ui->pushButton_7))
    {
        DialogPagina p;
        bool ok;

        p.pagina(modelliFiles.at(0), "7", _baseDir, _pagina, ok);

        if (ok == false)
            _pagina = "";
        else
            this->setVisible(false);
    }
    else
        ui->pushButton_7->setText(ui->pushButton_7->text() + "\n" + dialogEtichetta.etichetta("7"));
}
void DialogQuaderni::q8()
{
    if(hasName(ui->pushButton_8))
    {
        DialogPagina p;
        bool ok;

        p.pagina(modelliFiles.at(0), "8", _baseDir, _pagina, ok);

        if (ok == false)
            _pagina = "";
        else
            this->setVisible(false);
    }
    else
        ui->pushButton_8->setText(ui->pushButton_8->text() + "\n" + dialogEtichetta.etichetta("8"));
}
void DialogQuaderni::q9()
{
    if(hasName(ui->pushButton_9))
    {
        DialogPagina p;
        bool ok;

        p.pagina(modelliFiles.at(0), "9", _baseDir, _pagina, ok);

        if (ok == false)
            _pagina = "";
        else
            this->setVisible(false);
    }
    else
        ui->pushButton_9->setText(ui->pushButton_9->text() + "\n" + dialogEtichetta.etichetta("9"));
}
void DialogQuaderni::q10()
{
    if(hasName(ui->pushButton_10))
    {
        DialogPagina p;
        bool ok;

        p.pagina(modelliFiles.at(0), "10", _baseDir, _pagina, ok);

        if (ok == false)
            _pagina = "";
        else
            this->setVisible(false);
    }
    else
    {
        ui->pushButton_10->setText(ui->pushButton_10->text() + "\n" + dialogEtichetta.etichetta("10"));
    }

}

bool DialogQuaderni::hasName(QPushButton *button)
{
    return ((button->text().indexOf("di") + 2) < button->text().length());
}


QStringList DialogQuaderni::quaderni()
{
    QStringList list;

    for(int i = 0; i < 10; i++)
    {
        ui->pushButton_1->parent();

        QPushButton *button = (ui->pushButton_1->parent())->findChild<QPushButton *>("pushButton_" + QString("%1").arg(i));
        if(button)
        {

            if(hasName(button))
            {
                QString name = button->text();
                name = name.remove(0, name.indexOf("di") + 2);
                name.trimmed();
                list.append(name);
            }
        }
    }
    return list;
}

void DialogQuaderni::modelli(bool mostra)
{
    _mostraModelli = mostra;
    QStringList files;
    QString fileName;

    Modelli *modelli = new Modelli(_baseDir.absolutePath() + "/facilitoffice/");
    //qDebug() << "QUA\n";
    for (int i = 0; i < modelli->getModello().count(); i++) {
       fileName = modelli->getModello().at(i).at(0);
       fileName = fileName.remove(0, fileName.lastIndexOf(QDir::separator()) + 1);
       fileName.trimmed();
       files << fileName;
       //files << row.at(1);
       //qDebug() << "FILE " << fileName << endl;
    }
    dialogModelli.modello(quaderni(), files, modelliFiles, _baseDir);

    //qDebug() << "MODELLI SIZE = " << modelliFiles.size() << endl;

    //for (int i = 0; i < modelliFiles.size(); i++)
        //qDebug() << "MODELL " << modelliFiles.at(i);

    //delete modelli;
}


void DialogQuaderni::createMenu()
{

    menuImpostazioni = mb->addMenu(tr("&Impostazioni"));
    menuImpostazioni->addAction(maiuscoloAct);
    menuImpostazioni->addAction(modelliAct);
    menuNModelli = menuImpostazioni->addMenu("Numero Modelli");
    menuColorePulsanti = menuImpostazioni->addMenu("Colore pulsanti");
    menuEtichetta = mb->addMenu(tr("&Inserisci etichetta"));
    //menuImpostazioni->addAction(pulsantiAct);
    menuImpostazioni->addAction(focusAct);

    menuNModelli->addAction(unmAct);
    menuNModelli->addAction(duemAct);
    menuNModelli->addAction(tremAct);
    menuNModelli->addAction(quattromAct);
    menuNModelli->addAction(seimAct);
    menuNModelli->addAction(ottomAct);
    menuNModelli->addAction(diecimAct);

    menuColorePulsanti->addAction(coloreUnoAct);
    menuColorePulsanti->addAction(coloreDueAct);
    menuColorePulsanti->addAction(coloreTreAct);
    menuColorePulsanti->addAction(coloreQuattroAct);
    menuColorePulsanti->addAction(coloreCinqueAct);
    menuColorePulsanti->addAction(coloreSeiAct);
    menuColorePulsanti->addAction(coloreSetteAct);
    menuColorePulsanti->addAction(coloreOttoAct);
    menuColorePulsanti->addAction(coloreNoveAct);
    menuColorePulsanti->addAction(coloreDieciAct);

    menuEtichetta->addAction(etichettaUnoAct);
    menuEtichetta->addAction(etichettaDueAct);
    menuEtichetta->addAction(etichettaTreAct);
    menuEtichetta->addAction(etichettaQuattroAct);
    menuEtichetta->addAction(etichettaCinqueAct);
    menuEtichetta->addAction(etichettaSeiAct);
    menuEtichetta->addAction(etichettaSetteAct);
    menuEtichetta->addAction(etichettaOttoAct);
    menuEtichetta->addAction(etichettaNoveAct);
    menuEtichetta->addAction(etichettaDieciAct);


    gestModelliAct = mb->addAction(tr("&Modelli"));
    connect(gestModelliAct, SIGNAL(triggered()), this, SLOT(gestModelli()));
    chiudiAct = mb->addAction(tr("&Chiudi"));
    connect(chiudiAct, SIGNAL(triggered()), this, SLOT(accept()));



}


void DialogQuaderni::createActions()
{


     /*numeroAct = new QAction(tr("&New"), this);
     numeroAct->setShortcuts(QKeySequence::New);
     numeroAct->setStatusTip(tr("Create a new file"));
     connect(numeroAct, SIGNAL(triggered()), this, SLOT(newFile()));
*/
    maiuscoloAct = new QAction(tr("&Utilizza maiuscolo nelle etichette"), this);
     //maiuscoloAct->setShortcuts(QKeySequence::Open);
     //maiuscoloAct->setStatusTip(tr("Open an existing file"));
    maiuscoloAct->setCheckable(true);


    connect(maiuscoloAct, SIGNAL(triggered(bool)), this, SLOT(maiuscolo(bool)));

    modelliAct = new QAction(tr("&Modelli visibili all'apertura dei quaderni"), this);
    modelliAct->setCheckable(true);
    modelliAct->setChecked(true);

    unmAct = new QAction(tr("1"), this);
    unmAct->setCheckable(true);
    duemAct = new QAction(tr("2"), this);
    duemAct->setCheckable(true);

    tremAct = new QAction(tr("3"), this);
    tremAct->setCheckable(true);
    quattromAct = new QAction(tr("4"), this);
    quattromAct->setCheckable(true);
    seimAct = new QAction(tr("6"), this);
    seimAct->setCheckable(true);
    ottomAct = new QAction(tr("8"), this);
    ottomAct->setCheckable(true);
    diecimAct = new QAction(tr("10"), this);
    diecimAct->setCheckable(true);



    modelliGroup = new QActionGroup(this);
    modelliGroup->addAction(unmAct);
    modelliGroup->addAction(duemAct);
    modelliGroup->addAction(tremAct);
    modelliGroup->addAction(quattromAct);
    modelliGroup->addAction(seimAct);
    modelliGroup->addAction(ottomAct);
    modelliGroup->addAction(diecimAct);
    diecimAct->setChecked(true);

    modelliGroup->setExclusive(true);


    coloreUnoAct = new QAction(tr("1"), this);
    coloreDueAct = new QAction(tr("2"), this);
    coloreTreAct = new QAction(tr("3"), this);
    coloreQuattroAct = new QAction(tr("4"), this);
    coloreCinqueAct = new QAction(tr("5"), this);
    coloreSeiAct = new QAction(tr("6"), this);
    coloreSetteAct = new QAction(tr("7"), this);
    coloreOttoAct = new QAction(tr("8"), this);
    coloreNoveAct = new QAction(tr("9"), this);
    coloreDieciAct = new QAction(tr("10"), this);


    etichettaUnoAct = new QAction(tr("1"), this);
    etichettaDueAct = new QAction(tr("2"), this);
    etichettaTreAct = new QAction(tr("3"), this);
    etichettaQuattroAct = new QAction(tr("4"), this);
    etichettaCinqueAct = new QAction(tr("5"), this);
    etichettaSeiAct = new QAction(tr("6"), this);
    etichettaSetteAct = new QAction(tr("7"), this);
    etichettaOttoAct = new QAction(tr("8"), this);
    etichettaNoveAct = new QAction(tr("9"), this);
    etichettaDieciAct = new QAction(tr("10"), this);



    connect(unmAct, SIGNAL(triggered()), this, SLOT(showUno()));
    connect(duemAct, SIGNAL(triggered()), this, SLOT(showDue()));
    connect(tremAct, SIGNAL(triggered()), this, SLOT(showTre()));
    connect(quattromAct, SIGNAL(triggered()), this, SLOT(showQuattro()));
    connect(seimAct, SIGNAL(triggered()), this, SLOT(showSei()));
    connect(ottomAct, SIGNAL(triggered()), this, SLOT(showOtto()));
    connect(diecimAct, SIGNAL(triggered()), this, SLOT(showDieci()));



    connect(etichettaUnoAct, SIGNAL(triggered()), this, SLOT(etichettaUno()));
    connect(etichettaDueAct, SIGNAL(triggered()), this, SLOT(etichettaDue()));
    connect(etichettaTreAct, SIGNAL(triggered()), this, SLOT(etichettaTre()));
    connect(etichettaQuattroAct, SIGNAL(triggered()), this, SLOT(etichettaQuattro()));
    connect(etichettaCinqueAct, SIGNAL(triggered()), this, SLOT(etichettaCinque()));
    connect(etichettaSeiAct, SIGNAL(triggered()), this, SLOT(etichettaSei()));
    connect(etichettaSetteAct, SIGNAL(triggered()), this, SLOT(etichettaSette()));
    connect(etichettaOttoAct, SIGNAL(triggered()), this, SLOT(etichettaOtto()));
    connect(etichettaNoveAct, SIGNAL(triggered()), this, SLOT(etichettaNove()));
    connect(etichettaDieciAct, SIGNAL(triggered()), this, SLOT(etichettaDieci()));


    connect(coloreUnoAct, SIGNAL(triggered()), this, SLOT(coloreUno()));
    connect(coloreDueAct, SIGNAL(triggered()), this, SLOT(coloreDue()));
    connect(coloreTreAct, SIGNAL(triggered()), this, SLOT(coloreTre()));
    connect(coloreQuattroAct, SIGNAL(triggered()), this, SLOT(coloreQuattro()));
    connect(coloreCinqueAct, SIGNAL(triggered()), this, SLOT(coloreCinque()));
    connect(coloreSeiAct, SIGNAL(triggered()), this, SLOT(coloreSei()));
    connect(coloreSetteAct, SIGNAL(triggered()), this, SLOT(coloreSette()));
    connect(coloreOttoAct, SIGNAL(triggered()), this, SLOT(coloreOtto()));
    connect(coloreNoveAct, SIGNAL(triggered()), this, SLOT(coloreNove()));
    connect(coloreDieciAct, SIGNAL(triggered()), this, SLOT(coloreDieci()));


    //modelliAct->setStatusTip(tr("Save the document to disk"));

    connect(modelliAct, SIGNAL(triggered(bool)), this, SLOT(modelli(bool)));

    /*pulsantiAct = new QAction(tr("&Colore pulsanti"), this);
    connect(pulsantiAct, SIGNAL(triggered()), this, SLOT(colorePulsanti()));*/

    focusAct = new QAction(tr("&Colore pulsante con focus"), this);

    connect(focusAct, SIGNAL(triggered()), this, SLOT(coloreFocus()));

 }

void DialogQuaderni::coloreFocus()
{
}

void DialogQuaderni::colorePulsanti()
{
}

void DialogQuaderni::maiuscolo(bool check)
{
    if ((_maiuscolo = check)) {
        ui->pushButton_1->setText(ui->pushButton_1->text().toUpper());
        ui->pushButton_2->setText(ui->pushButton_2->text().toUpper());
        ui->pushButton_3->setText(ui->pushButton_3->text().toUpper());
        ui->pushButton_4->setText(ui->pushButton_4->text().toUpper());
        ui->pushButton_5->setText(ui->pushButton_5->text().toUpper());
        ui->pushButton_6->setText(ui->pushButton_6->text().toUpper());
        ui->pushButton_7->setText(ui->pushButton_7->text().toUpper());
        ui->pushButton_8->setText(ui->pushButton_8->text().toUpper());
        ui->pushButton_9->setText(ui->pushButton_9->text().toUpper());
        ui->pushButton_10->setText(ui->pushButton_10->text().toUpper());
    } else {
        ui->pushButton_1->setText(ui->pushButton_1->text().toLower());
        ui->pushButton_2->setText(ui->pushButton_2->text().toLower());
        ui->pushButton_3->setText(ui->pushButton_3->text().toLower());
        ui->pushButton_4->setText(ui->pushButton_4->text().toLower());
        ui->pushButton_5->setText(ui->pushButton_5->text().toLower());
        ui->pushButton_6->setText(ui->pushButton_6->text().toLower());
        ui->pushButton_7->setText(ui->pushButton_7->text().toLower());
        ui->pushButton_8->setText(ui->pushButton_8->text().toLower());
        ui->pushButton_9->setText(ui->pushButton_9->text().toLower());
        ui->pushButton_10->setText(ui->pushButton_10->text().toLower());
    }
}

void DialogQuaderni::gestModelli()
{
    QStringList files;
    QString fileName;



    Modelli *modelli = new Modelli(_baseDir.absolutePath() + "/facilitoffice/");

    for (int i = 0; i < modelli->getModello().count(); i++) {
       fileName = modelli->getModello().at(i).at(0);
       fileName = fileName.remove(0, fileName.lastIndexOf(QDir::separator()) + 1);
       fileName.trimmed();
       files << fileName;
       //files << row.at(1);
    }
    dialogModelli.modello(quaderni(), files, modelliFiles, _baseDir);
    //for (int i = 0; i < modelliFiles.size(); i++)
        //qDebug() << i << " MODELLO SELECTED " << modelliFiles.at(i) << endl;
}


void DialogQuaderni::accept()
{
    QDialog::accept();
}

void DialogQuaderni::showUno()
{
    _numeroQuaderni = 1;
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->pushButton_8->setVisible(false);
    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);
}

void DialogQuaderni::showDue()
{
    _numeroQuaderni = 2;
    ui->pushButton_2->setVisible(true);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->pushButton_8->setVisible(false);
    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);
}

void DialogQuaderni::showTre()
{
    _numeroQuaderni = 3;
    ui->pushButton_2->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->pushButton_8->setVisible(false);
    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);
}

void DialogQuaderni::showQuattro()
{
    _numeroQuaderni = 4;
    ui->pushButton_2->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(true);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->pushButton_8->setVisible(false);
    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);
}

void DialogQuaderni::showSei()
{
    _numeroQuaderni = 6;
    ui->pushButton_2->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(true);
    ui->pushButton_5->setVisible(true);
    ui->pushButton_6->setVisible(true);
    ui->pushButton_7->setVisible(false);
    ui->pushButton_8->setVisible(false);
    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);
}

void DialogQuaderni::showOtto()
{
    _numeroQuaderni = 8;
    ui->pushButton_2->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(true);
    ui->pushButton_5->setVisible(true);
    ui->pushButton_6->setVisible(true);
    ui->pushButton_7->setVisible(true);
    ui->pushButton_8->setVisible(true);
    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);
}

void DialogQuaderni::showDieci()
{
    _numeroQuaderni = 10;
    ui->pushButton_2->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(true);
    ui->pushButton_5->setVisible(true);
    ui->pushButton_6->setVisible(true);
    ui->pushButton_7->setVisible(true);
    ui->pushButton_8->setVisible(true);
    ui->pushButton_9->setVisible(true);
    ui->pushButton_10->setVisible(true);
}

void DialogQuaderni::coloreUno()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QPalette palette;
        palette.setColor(QPalette::Button, color);
        ui->pushButton_1->setPalette(palette);
        colors[0] = color;
    }

}

void DialogQuaderni::coloreDue()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QPalette palette;
        palette.setColor(QPalette::Button, color);
        ui->pushButton_2->setPalette(palette);
        colors[1] = color;
    }
}

void DialogQuaderni::coloreTre()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QPalette palette;
        palette.setColor(QPalette::Button, color);
        ui->pushButton_3->setPalette(palette);
        colors[2] = color;
    }
}

void DialogQuaderni::coloreQuattro()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QPalette palette;
        palette.setColor(QPalette::Button, color);
        ui->pushButton_4->setPalette(palette);
        colors[3] = color;
    }
}

void DialogQuaderni::coloreCinque()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QPalette palette;
        palette.setColor(QPalette::Button, color);
        ui->pushButton_5->setPalette(palette);
        colors[4] = color;
    }
}

void DialogQuaderni::coloreSei()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QPalette palette;
        palette.setColor(QPalette::Button, color);
        ui->pushButton_6->setPalette(palette);
        colors[5] = color;
    }
}

void DialogQuaderni::coloreSette()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QPalette palette;
        palette.setColor(QPalette::Button, color);
        ui->pushButton_7->setPalette(palette);
        colors[6] = color;
    }
}

void DialogQuaderni::coloreOtto()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QPalette palette;
        palette.setColor(QPalette::Button, color);
        ui->pushButton_8->setPalette(palette);
        colors[7] = color;
    }
}

void DialogQuaderni::coloreNove()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QPalette palette;
        palette.setColor(QPalette::Button, color);
        ui->pushButton_9->setPalette(palette);
        colors[8] = color;
    }
}


void DialogQuaderni::coloreDieci()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        QPalette palette;
        palette.setColor(QPalette::Button, color);
        ui->pushButton_10->setPalette(palette);
        colors[9] = color;
    }
}





void DialogQuaderni::etichettaUno()
{
    ui->pushButton_1->setText(ui->pushButton_1->text() + "\n" + ((_maiuscolo)?dialogEtichetta.etichetta("1").toUpper():dialogEtichetta.etichetta("1")));
}


void DialogQuaderni::etichettaDue()
{
    ui->pushButton_2->setText(ui->pushButton_2->text() + "\n" + ((_maiuscolo)?dialogEtichetta.etichetta("2").toUpper():dialogEtichetta.etichetta("2")));
}


void DialogQuaderni::etichettaTre()
{
    ui->pushButton_3->setText(ui->pushButton_3->text() + "\n" + ((_maiuscolo)?dialogEtichetta.etichetta("3").toUpper():dialogEtichetta.etichetta("3")));
}


void DialogQuaderni::etichettaQuattro()
{
    ui->pushButton_4->setText(ui->pushButton_4->text() + "\n" + ((_maiuscolo)?dialogEtichetta.etichetta("4").toUpper():dialogEtichetta.etichetta("4")));
}



void DialogQuaderni::etichettaCinque()
{
    ui->pushButton_5->setText(ui->pushButton_5->text() + "\n" + ((_maiuscolo)?dialogEtichetta.etichetta("5").toUpper():dialogEtichetta.etichetta("5")));
}


void DialogQuaderni::etichettaSei()
{
    ui->pushButton_6->setText(ui->pushButton_6->text() + "\n" + ((_maiuscolo)?dialogEtichetta.etichetta("6").toUpper():dialogEtichetta.etichetta("6")));
}


void DialogQuaderni::etichettaSette()
{
    ui->pushButton_7->setText(ui->pushButton_7->text() + "\n" + ((_maiuscolo)?dialogEtichetta.etichetta("7").toUpper():dialogEtichetta.etichetta("7")));
}


void DialogQuaderni::etichettaOtto()
{
    ui->pushButton_8->setText(ui->pushButton_8->text() + "\n" + ((_maiuscolo)?dialogEtichetta.etichetta("8").toUpper():dialogEtichetta.etichetta("8")));
}


void DialogQuaderni::etichettaNove()
{
    ui->pushButton_9->setText(ui->pushButton_9->text() + "\n" + ((_maiuscolo)?dialogEtichetta.etichetta("9").toUpper():dialogEtichetta.etichetta("9")));
}

void DialogQuaderni::etichettaDieci()
{
    ui->pushButton_10->setText(ui->pushButton_10->text() + "\n" + ((_maiuscolo)?dialogEtichetta.etichetta("10").toUpper():dialogEtichetta.etichetta("10")));
}



void DialogQuaderni::openQuaderni(QStringList &names, QList<QColor> &cols, bool &maiuscole, QDir baseDir, QColor &focus, int &visibili, QString &page)
{
    QString quaderno;
    QDir dir;

    if (modelliFiles.size() == 0)
        for (int i = 0; i < 10; i++)
            modelliFiles << "";

    //qDebug() << "SIZE " << modelliFiles.size() << endl;

    _maiuscolo = maiuscole;

    maiuscoloAct->setChecked(_maiuscolo);

    switch(visibili)
    {
        case 1:
            unmAct->setChecked(true);
            break;
        case 2:
            duemAct->setChecked(true);
        case 3:
            tremAct->setChecked(true);
            break;
        case 4:
            quattromAct->setChecked(true);
            break;
        case 6:
            seimAct->setChecked(true);
            break;
        case 8:
            ottomAct->setChecked(true);
            break;

        case 10:
        default:
            diecimAct->setChecked(true);
            break;
    }





    for(int i = 0; i < names.size() && i < 10; i++)
    {
        ui->pushButton_1->parent();

        QPushButton *button = (ui->pushButton_1->parent())->findChild<QPushButton *>("pushButton_" + QString("%1").arg(i));
        if(button)
        {

            button->setText(((_maiuscolo)?names.at(i).toUpper():names.at(i)));
            if (i >= visibili)
                button->setVisible(false);

        }

        if (cols.at(i).isValid()) {
            QPalette palette;
            palette.setColor(QPalette::Button, cols.at(i));
            button->setPalette(palette);

        }
    }


    _baseDir = baseDir;


    dir.setPath(_baseDir.absolutePath() + "/facilitoffice");

    if (dir.exists() == false) {
        dir.mkdir(dir.absolutePath());
    }

    dir.setPath(_baseDir.absolutePath() + "/facilitoffice/modelli");

    if (dir.exists() == false)
        dir.mkdir(dir.absolutePath());


    dir.setPath(_baseDir.absolutePath() + "/facilitoffice/quaderni");

    if (dir.exists() == false)
        dir.mkdir(dir.absolutePath());



    for (int i = 1; i < 11; i++) {
        quaderno.setNum(i);
        dir.setPath(QDir::homePath() + "facilitoffice/quaderni/" + quaderno);

        if (dir.exists() == false)
            dir.mkdir(dir.absolutePath());

    }

    this->exec();

    names.clear();
    for(int i = 0; i < names.size() && i < 10; i++)
    {
        ui->pushButton_1->parent();

        QPushButton *button = (ui->pushButton_1->parent())->findChild<QPushButton *>("pushButton_" + QString("%1").arg(i));
        if(button)
        {
           names << button->text();
        }
    }
    maiuscole = _maiuscolo;
    cols = colors;
    visibili = _numeroQuaderni;
    page = _pagina;
    qDebug() << "PAGINA = " << page << endl;
}

void DialogQuaderni::closeEvent(QCloseEvent *event)
{

    event->ignore();
    QDialog::setVisible(false);

}

DialogQuaderni::~DialogQuaderni()
{
    delete ui;
}
