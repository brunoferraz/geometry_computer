#ifndef LINE_H
#define LINE_H

#include <Display/Primitives/basicgeometry.h>

class Line : public BasicGeometry
{
public:
    Line();
    void display();
    void displayObject();

    void configMaterial();
    void configRender();

    void addVertexfv(Eigen::Vector3f v);
    void finishIncremental();

};

#endif // LINE_H
