#include "glcanvas.h"


GLcanvas::GLcanvas(QWidget *parent) :
    QGLWidget(parent)
{
//    points.push_back(Point_2(0, 0));
//    points.push_back(Point_2(0.5, 0));
//    points.push_back(Point_2(0, 0.5));
//    points.push_back(Point_2(0.5, 0.5));

//    std::vector<Point_2> npoints, result;
//    npoints = points.toVector().toStdVector();

//   CGAL::convex_hull_2(npoints.begin(), npoints.end(), std::back_inserter(result) );
//   std::cout << result.size() << std::endl;
    polyhedronStudy();
}

void GLcanvas::polyhedronStudy()
{
    Point_3 p( 0.7, 0.0, 0.0);
    Point_3 q( 0.0, 0.7, 0.0);
    Point_3 r( 0.0, 0.0, 0.7);
    Point_3 s( 0.0, 0.0, 0.0);
    P.make_tetrahedron( p, q, r, s);

   // CGAL::Hald

    //CGAL_For_all()
}

void GLcanvas::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    qglClearColor(Qt::black);
    float ratio = float(this->width())/ float(this->height());
    glViewport(0, 0, this->width(), this->height());
    glOrtho(-ratio, ratio, -1, 1, -10, 10);
}

void GLcanvas::paintGL()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glColor3f(1, 1, 1);
     glBegin(GL_POINTS);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
     glEnd();
    glColor3f(1, 0, 0);
    glPointSize(3);
    glBegin(GL_POINTS);
//        Vertex_iterator v;
//        for(v = P.vertices_begin(); v != P.vertices_end(); ++v){
//            Point_3 p = v->point();
//            glVertex3f(p.x(), p.y(), p.z());
//        }
        Point_3 p = P.vertices_begin()->point();

        std::cout << p.transform << std::endl;
//        Halfedge_iterator H;
//        for(H = P.halfedges_begin(); H!= P.halfedges_end(); ++H){
//            //std::cout << H-> << std::endl;
//        }
    glEnd();
}
