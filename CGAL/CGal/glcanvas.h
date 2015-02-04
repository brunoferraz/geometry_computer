#ifndef GLCANVAS_H
#define GLCANVAS_H

#include <QGLWidget>
#include <iostream>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>
#include <QList>
#include <CGAL/Cartesian.h>
#include <CGAL/Polyhedron_3.h>

//typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
//typedef K::Point_2 Point_2;

typedef CGAL::Simple_cartesian<double> Kernel;
typedef CGAL::Polyhedron_3<Kernel>  Polyhedron;
typedef Polyhedron::Vertex_iterator Vertex_iterator;
typedef Polyhedron::Facet_iterator Facet_iterator;
typedef Polyhedron::Halfedge_iterator Halfedge_iterator;
typedef Polyhedron::Halfedge_handle Halfedge_handle;
typedef Kernel::Point_3 Point_3;

class GLcanvas : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLcanvas(QWidget *parent = 0);

//    QList<Point_2> points;

    Polyhedron P;
    void polyhedronStudy();

    void initializeGL();
    void paintGL();

signals:

public slots:

};

#endif // GLCANVAS_H
