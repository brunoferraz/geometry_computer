#include "polygon.h"

Polygon::Polygon(QList<Vector4d> vList)
{
    minX = 0;
    minY = 0;
    maxX = 0;
    maxY = 0;
    currentVertexIndex = 0;
    vertexList = vList;
}

Vector4d Polygon::getCurrentVertex()
{
    return vertexList.at(currentVertexIndex);
}

Vector4d Polygon::getVertex(int i)
{
    return vertexList.at(i);
}

Vector4d Polygon::getNextVertex()
{
    currentVertexIndex++;
    return getCurrentVertex();
}

Vector4d Polygon::getPrevVertex()
{
    currentVertexIndex--;
    return getCurrentVertex();
}

Vector4d Polygon::getNextCirculationVertex()
{
    currentVertexIndex++;
    if(currentVertexIndex >= vertexList.length()){
        currentVertexIndex = 0;
    }
    return getCurrentVertex();
}

Vector4d Polygon::getPrevCirculationVertex()
{
    currentVertexIndex--;
    if(currentVertexIndex < 0){
        currentVertexIndex = vertexList.length() -1;
    }
    return getCurrentVertex();
}

void Polygon::addVertex(Vector4d v)
{
    vertexList.push_back(v);
}
