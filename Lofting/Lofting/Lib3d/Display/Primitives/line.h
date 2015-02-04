#ifndef LINE_H
#define LINE_H

#include <Display/Primitives/basicgeometry.h>

class Line : public BasicGeometry
{
public:
    Line();

    bool finished;

    void display();
    void displayObject();

    void configMaterial();
    void configRender();

    void addVertexf(Eigen::Vector3f v);
    void addVertexf(float _x, float _y, float _z);
    void finishIncremental();
};

#endif // LINE_H
