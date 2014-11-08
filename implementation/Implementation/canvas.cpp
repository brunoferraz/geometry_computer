#include "canvas.h"

Canvas::Canvas(QWidget *parent) :
    QWidget(parent)
{
    resize(parent->size());
    lineList = new QList<Vector4d>;
}
void Canvas::linkList(QList<Vector4d> &l)
{
    pointList = &l;
    update();
}
void Canvas::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    if(pointList->length()>0){
        for(int i =0; i < pointList->length(); i++){
            painter.drawEllipse(QPoint(pointList->at(i)(0), pointList->at(i)(1)), 5, 5);
        }
    }
    if(lineList->length()>1){
        for(int i =1; i < lineList->length(); i++){
            painter.drawLine(lineList->at(i-1)(0), lineList->at(i-1)(1),lineList->at(i)(0), lineList->at(i)(1));
        }
        painter.drawLine(lineList->at(lineList->length()-1)(0), lineList->at(lineList->length()-1)(1),lineList->at(0)(0), lineList->at(0)(1));
    }
}
