#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include <eigen3/Eigen/Dense>
#include <QVector>
#include <QList>
#include <QDebug>
#include <QtAlgorithms>
#include <util.h>
#include <math.h>


using namespace std;
using namespace Eigen;
class ConvexHull
{
public:
    ConvexHull();

//    QList<Vector4d> list;
//    QList<Vector4d> convexHull;
//    int maxY;
//    int maxX;

    void addPoint(Vector4d &p);
    QList<Vector4d> orderByAngle(QList<Vector4d> &list);
    QList<Vector4d> findConvexHull(QList<Vector4d> &list);
    QList<QList<Vector4d>> divideAndConquer(QList<Vector4d> &list);
};

#endif // CONVEXHULL_H
