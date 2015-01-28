#ifndef VIEWPORTORTOTOP_H
#define VIEWPORTORTOTOP_H

#include <View/viewportorto.h>

class ViewPortOrtoTop : public ViewPortOrto
{
public:
    ViewPortOrtoTop();
    void configProjection();
    Eigen::Vector3f getTranslateFromScreen(float x, float y);
    Eigen::Vector3f getDrawVertexPosition(float x, float y);
};

#endif // VIEWPORTORTOTOP_H
