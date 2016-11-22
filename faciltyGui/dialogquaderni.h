#ifndef DIALOGQUADERNI_H
#define DIALOGQUADERNI_H

#include <QtWidgets/QDialog>
#include "dialogetichetta.h"
#include "dialogmodelli.h"
#include <QDebug>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QAction>
#include <QCloseEvent>

namespace Ui
{
    class DialogQuaderni;
}

class DialogQuaderni : public QDialog
{
    Q_OBJECT

public:
    DialogQuaderni(QWidget *parent = 0);
    ~DialogQuaderni();
    void closeEvent(QCloseEvent *event);
    void openQuaderni(QStringList &names, QList<QColor> &cols, bool &maiuscole, QDir baseDir, QColor &focus,  int &visibili, QString &page);
private:
    Ui::DialogQuaderni *ui;
    bool hasName(QPushButton *);
    QStringList quaderni();
    QStringList modelliFiles;
    DialogEtichetta dialogEtichetta;
    DialogModelli dialogModelli;
    QMenuBar *mb ;
    QMenu *menuImpostazioni;
    QMenu *menuModelli;
    QMenu *menuChiudi;
    QMenu *menuNModelli;
    QMenu *menuColorePulsanti;
    QMenu *menuEtichetta;
    QAction *maiuscoloAct;
    QAction *modelliAct;
    QAction *pulsantiAct;
    QAction *focusAct;
    QAction *gestModelliAct;
    QAction *chiudiAct;
    QAction *unmAct;
    QAction *duemAct;
    QAction *tremAct;
    QAction *quattromAct;
    QAction *seimAct;
    QAction *ottomAct;
    QAction *diecimAct;
    QAction *coloreUnoAct;
    QAction *coloreDueAct;
    QAction *coloreTreAct;
    QAction *coloreQuattroAct;
    QAction *coloreCinqueAct;
    QAction *coloreSeiAct;
    QAction *coloreSetteAct;
    QAction *coloreOttoAct;
    QAction *coloreNoveAct;
    QAction *coloreDieciAct;
    QAction *etichettaUnoAct;
    QAction *etichettaDueAct;
    QAction *etichettaTreAct;
    QAction *etichettaQuattroAct;
    QAction *etichettaCinqueAct;
    QAction *etichettaSeiAct;
    QAction *etichettaSetteAct;
    QAction *etichettaOttoAct;
    QAction *etichettaNoveAct;
    QAction *etichettaDieciAct;
    QActionGroup *modelliGroup;
    void createMenu();
    void createActions();
    bool _maiuscolo;
    bool _mostraModelli;
    int _numeroQuaderni;

    QList<QColor> colors;
    QColor focusColor;
    QDir _baseDir;
    QStringList _names;
    int _visibili;
    QString _pagina;
private slots:
    void q1();
    void q2();
    void q3();
    void q4();
    void q5();
    void q6();
    void q7();
    void q8();
    void q9();
    void q10();
    void modelli(bool mostra);
    void coloreFocus();
    void colorePulsanti();
    void maiuscolo(bool check);
    void gestModelli();
    void accept();
    void showUno();
    void showDue();
    void showTre();
    void showQuattro();
    void showSei();
    void showOtto();
    void showDieci();
    void coloreUno();
    void coloreDue();
    void coloreTre();
    void coloreQuattro();
    void coloreCinque();
    void coloreSei();
    void coloreSette();
    void coloreOtto();
    void coloreNove();
    void coloreDieci();
    void etichettaUno();
    void etichettaDue();
    void etichettaTre();
    void etichettaQuattro();
    void etichettaCinque();
    void etichettaSei();
    void etichettaSette();
    void etichettaOtto();
    void etichettaNove();
    void etichettaDieci();
signals:
    void loadPagina(QString pagina);
};

#endif // DIALOGQUADERNI_H
