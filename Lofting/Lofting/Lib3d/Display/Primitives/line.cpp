#include "line.h"

Line::Line()
{
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

void Line::addVertexfv(Eigen::Vector3f v)
{
    vertexList.push_back(v);
}

void Line::finishIncremental()
{

}
