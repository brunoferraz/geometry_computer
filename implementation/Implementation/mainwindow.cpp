#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas = new Canvas(this);
    canvas->pointList = &pointList;
    canvas->lineList = &lineList;
    canvas->polygonList = &polygonList;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
//    if(ev->button() == Qt::LeftButton){
//        Vector4d v;
//        v<< ev->pos().x(), ev->pos().y(), 0, 0;
//        pointList.push_back(v);
//    }else{
//        lineList = glist.findConvexHull(pointList);
//    }
//    canvas->update();
    if(ev->button() == Qt::LeftButton){
//        Vector4d v;
//        v<< ev->pos().x(), ev->pos().y(), 0, 0;
//        pointList.push_back(v);
           for(int i = 0; i < 6; i ++){
                Vector4d v;
                int w;
                w = (float(std::rand()%(this->size().width() - 100))) + 50;
                int h;
                h= (float(std::rand()%(this->size().height() - 100))) + 50;
                v << w, h, 0, 0;
                pointList.push_back(v);
            }
            canvas->update();
    }else if(ev->button() == Qt::RightButton){
        if(pointList.length()>=3){
//          polygonList = glist.divideAndConquer(pointList);
            lineList = glist.findConvexHull(pointList);
            polygonList = glist.divideAndConquer(pointList);
            canvas->update();
        }
    }else if(ev->button() == Qt::MiddleButton){
        pointList.clear();
        lineList.clear();
        polygonList.clear();
        canvas->update();
    }
}
