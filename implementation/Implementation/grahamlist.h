#ifndef GRAHAMLIST_H
#define GRAHAMLIST_H

#include <eigen3/Eigen/Dense>
#include <QVector>
#include <QList>
#include <QDebug>
#include <QtAlgorithms>
#include <util.h>
#include <math.h>


using namespace std;
using namespace Eigen;
class GrahamList
{
public:
    GrahamList();

    QList<Vector4d> list;
    QList<Vector4d> convexHull;
    int maxY;
    int maxX;

    void addPoint(Vector4d &p);
    void orderByAngle();
    void findConvexHull();
};

#endif // GRAHAMLIST_H
