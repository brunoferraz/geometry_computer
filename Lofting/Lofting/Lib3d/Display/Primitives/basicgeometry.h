#ifndef BASICHEDRON_H
#define BASICHEDRON_H

#include <Display/abstractobj.h>

#include <Display/UiElements/axis3d.h>
#include <Display/UiElements/boundingbox.h>

#include <CGAL/Simple_cartesian.h>
#include <CGAL/HalfedgeDS_vector.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Point_3.h>
#include <CGAL/Plane_3.h>

#include <QString>

typedef CGAL::Simple_cartesian<double>                  Kernel;
typedef Kernel::Point_3                                 Point_3;
typedef Kernel::Plane_3                                 Plane_3;
typedef CGAL::Polyhedron_3<Kernel>                      Polyhedron;
typedef Polyhedron::Facet_iterator                      Facet_iterator;
typedef Polyhedron::Facet_handle                        Facet_handle;
typedef Polyhedron::Halfedge_around_facet_circulator    Halfedge_facet_circulator;

typedef Polyhedron::Vertex_iterator                     Vertex_iterator;

inline Polyhedron::Plane_3 plane_from_facet(Polyhedron::Facet& f) {
    Polyhedron::Halfedge_handle h = f.halfedge();
    return Polyhedron::Plane_3( 	h->vertex()->point(),
                                    h->next()->vertex()->point(),
                                    h->opposite()->vertex()->point());
}

class BasicGeometry : public AbstractObj
{
    Q_OBJECT
public:
    explicit BasicGeometry(QObject *parent = 0);
    Polyhedron P;
    BoundingBox boundingBox;
    Axis3d axis;

    void display();

    virtual void displayObject();
    virtual void displayGizmos();
signals:

public slots:

};

#endif // BASICHEDRON_H
