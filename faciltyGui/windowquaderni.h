#ifndef WINDOWQUADERNI_H
#define WINDOWQUADERNI_H

#include <QtWidgets/QMainWindow>

namespace Ui
{
    class MainWindow;
}


class WindowQuaderni : public QMainWindow
{
     Q_OBJECT
    private:
        Ui::MainWindow *ui;
public:
    WindowQuaderni(QWidget *parent = 0);
    ~WindowQuaderni();
public slots:
    void quaderno1();
};

#endif // WINDOWQUADERNI_H
