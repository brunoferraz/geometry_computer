#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include <iostream>
#include <stdio.h>
#include <eigen3/Eigen/Dense>
#include <convexhull.h>
#include <QPaintEvent>
#include <QPainter>
#include <QPoint>
#include <QVector>
#include <QList>
#include <QDebug>
using namespace std;
using namespace Eigen;
class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);
    QList<Vector4d> *pointList;
    QList<Vector4d> *lineList;

    void linkList(QList<Vector4d> &l);
signals:

public slots:

protected:
    //void mouseReleaseEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *ev);
};

#endif // CANVAS_H
