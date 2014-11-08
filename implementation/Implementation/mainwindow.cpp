#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas = new Canvas(this);
    canvas->linkList(glist.list);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton){
        Vector4d v;
        v<< ev->pos().x(), ev->pos().y(), 0, 0;
        glist.addPoint(v);
        canvas->linkList(glist.list);
    }else{
       glist.findConvexHull();
       *canvas->pointList = glist.list;
       *canvas->lineList = glist.convexHull;
       canvas->update();
    }
}
