#include "viewportortoleft.h"

ViewPortOrtoLeft::ViewPortOrtoLeft()
{
}

void ViewPortOrtoLeft::configProjection()
{
    ViewPortOrto::configProjection();
    rotate(90, 0, 1, 0);
}

Eigen::Vector3f ViewPortOrtoLeft::getTranslateFromScreen(float x, float y)
{
    Eigen::Vector3f nPos;
    nPos << 0.0, -y, x;
    return nPos;
}

Eigen::Vector3f ViewPortOrtoLeft::getDrawVertexPosition(float x, float y)
{
    Eigen::Vector3f pos = ViewPort::getDrawVertexPosition(x, y);
    Eigen::Vector3f nPos;
    nPos << 0, -pos(1), pos(0);
    return nPos;
}
