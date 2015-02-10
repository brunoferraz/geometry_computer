#ifndef LOFTTOOL_H
#define LOFTTOOL_H

#include <Tools/tool.h>
#include <Tools/selectTool.h>
#include <QList>
#include <Display/abstractobj.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Polyhedron_3.h>

typedef CGAL::Simple_cartesian<double>                  Kernel;
typedef Kernel::Point_3                                 Point_3;
typedef CGAL::Polyhedron_3<Kernel>                      Polyhedron;
typedef Polyhedron::Facet_iterator                      Facet_iterator;
typedef Polyhedron::Facet_handle                        Facet_handle;
typedef Polyhedron::Halfedge_around_facet_circulator    Halfedge_facet_circulator;

typedef Polyhedron::Vertex_iterator                     Vertex_iterator;
typedef Polyhedron::Halfedge_handle                     Halfedge_handle;



class LoftTool : public SelectTool
{
public:
    LoftTool();

    QList<AbstractObj *> listShapes;
    AbstractObj *path;

    void mousePress();
    void processShapes();
signals:
    void applyClicked();
};

#endif // LOFTTOOL_H
