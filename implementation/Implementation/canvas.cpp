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
    pointList->pop_back();
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
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    if(lineList->length()>1){
        for(int i =1; i < lineList->length(); i++){
            painter.drawLine(lineList->at(i-1)(0), lineList->at(i-1)(1),lineList->at(i)(0), lineList->at(i)(1));
        }
        painter.drawLine(lineList->at(lineList->length()-1)(0), lineList->at(lineList->length()-1)(1),lineList->at(0)(0), lineList->at(0)(1));
    }
    pen.setWidth(1);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    if(polygonList->length()>1){
         for(int i =0; i < polygonList->length(); i++){
            QList <Vector4d> polygon = polygonList->at(i);
            for(int j=1; j<polygon.length();j++){
                painter.drawLine(polygon.at(j-1)(0), polygon.at(j-1)(1),polygon.at(j)(0), polygon.at(j)(1));
            }
            painter.drawLine(polygon.at(polygon.length()-1)(0), polygon.at(polygon.length()-1)(1),polygon.at(0)(0), polygon.at(0)(1));
         }
    }
}
