#ifndef LOFTTOOL_H
#define LOFTTOOL_H

#include <Tools/tool.h>
#include <Tools/selectTool.h>
#include <QList>
#include <Display/abstractobj.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/HalfedgeDS_default.h>
#include <CGAL/Polyhedron_traits_3.h>
#include <CGAL/Polyhedron_incremental_builder_3.h>
#include <CGAL/Polyhedron_3.h>

//typedef CGAL::Simple_cartesian<double>      Kernel;
//typedef CGAL::HalfedgeDS_default<Kernel>    HDS;
//typedef CGAL::Polyhedron_traits_3<Kernel>   Traits;
//typedef Polyhedron::Halfedge_handle         Halfedge_handle;

typedef CGAL::Simple_cartesian<double>      K;
typedef CGAL::Polyhedron_3<K>               Polyhedron;
typedef Polyhedron::Halfedge_handle         Halfedge_handle;
typedef Polyhedron::Point_3                 Point_3;
typedef Polyhedron::Facet_const_iterator    Facet_const_iterator;

using CGAL::Modifier_base;

template <class HDS>
class Build_triangle : public CGAL::Modifier_base<HDS> {

public:
    Point_3 p1, p2, p3;
    Build_triangle(Point_3 _p1, Point_3 _p2, Point_3 _p3 )
        :p1(_p1), p2(_p2), p3(_p3)
    {}
    inline void setPoints(Point_3 _p1, Point_3 _p2, Point_3 _p3 ){p1 = _p1; p2 = _p2; p3 = _p3;}
    void operator()(HDS& hds) {
        // Postcondition: hds is a valid polyhedral surface.
        CGAL::Polyhedron_incremental_builder_3<HDS> B( hds, true);
        B.begin_surface( 3, 1, 6);
        B.add_vertex(p1);
        B.add_vertex(p2);
        B.add_vertex(p3);
        B.begin_facet();
        B.add_vertex_to_facet( 0);
        B.add_vertex_to_facet( 1);
        B.add_vertex_to_facet( 2);
        B.end_facet();
        B.end_surface();
    }
};

class LoftTool : public SelectTool
{
public:
    LoftTool();

    QList<AbstractObj *> listShapes;
    AbstractObj *path;

    void mousePress();
    void processShapes();
    void processShapes2();
    AbstractObj* changeSide(AbstractObj *A, AbstractObj *B, bool &side);
signals:
    void applyClicked();
};

#endif // LOFTTOOL_H
