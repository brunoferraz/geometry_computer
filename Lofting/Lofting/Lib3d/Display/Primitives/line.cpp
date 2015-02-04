#include "line.h"

Line::Line()
{
    finished = false;
}

void Line::display()
{
    BasicGeometry::display();
//    displayObject();
//    displayGizmos();
}

void Line::displayObject()
{
    glPointSize(7);
    glBegin(GL_POINTS);
    for(int i = 0; i < vertexList.length() ; i++){
            glVertex3fv(vertexList.at(i).data());
    }
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    for(int i = 0; i < vertexList.length() ; i++){
            glVertex3fv(vertexList.at(i).data());
    }
    glEnd();
}

void Line::configMaterial()
{

}

void Line::configRender()
{

}

void Line::addVertexf(Eigen::Vector3f v)
{
    vertexList.push_back(v);
}
void Line::addVertexf(float _x, float _y, float _z)
{
    Eigen::Vector3f v;
    v   << _x, _y, _z;
    vertexList.push_back(v);
}

void Line::finishIncremental()
{
    if(!finished){
        float dx, dy, dz,xMin, xMax, yMin, yMax, zMin, zMax;
        dx = dy = dz = xMin =  xMax = yMin = yMax = zMin= zMax=0;
        xMax = xMin = vertexList.at(0)(0);
        yMax = yMin = vertexList.at(0)(1);
        zMax = zMin = vertexList.at(0)(2);
        for(int i = 0; i < vertexList.length(); i++)
        {
            xMin = std::min(xMin, vertexList.at(i)(0));
            yMin = std::min(yMin, vertexList.at(i)(1));
            zMin = std::min(zMin, vertexList.at(i)(2));

            xMax = std::max(xMax, vertexList.at(i)(0));
            yMax = std::max(yMax, vertexList.at(i)(1));
            zMax = std::max(zMax, vertexList.at(i)(2));
        }
        dx = std::abs(xMax - xMin);
        dy = std::abs(yMax - yMin);
        dz = std::abs(zMax - zMin);
        Eigen::Vector3f delta;
        delta << xMin + dx/2,
                 yMin + dy/2,
                 zMin + dz/2;

        for(int i = 0; i < vertexList.length(); i++)
        {
            Eigen::Vector3f v;
            v = vertexList.at(i) - delta;
            vertexList.replace(i,v);
        }
        setPos(delta);
        finished = true;
    }
}
