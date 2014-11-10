#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <canvas.h>
#include <stdio.h>
#include <iostream>
#include <QMouseEvent>
#include <eigen3/Eigen/Dense>
#include <convexhull.h>
using namespace Eigen;
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Canvas *canvas;
    ConvexHull glist;

    void mouseReleaseEvent(QMouseEvent *ev);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
