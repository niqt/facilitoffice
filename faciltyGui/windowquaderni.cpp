#include "ui_quaderniwindow.h"
#include "windowquaderni.h"

WindowQuaderni::WindowQuaderni(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void WindowQuaderni::quaderno1()
{
    ui->quaderno10PushButton->setText("Quaderno di matematica");
}


WindowQuaderni::~WindowQuaderni()
{
    delete ui;
}
