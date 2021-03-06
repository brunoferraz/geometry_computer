#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <Eigen/Dense>
#include <QString>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QDebug>
//using namespace Eigen;
struct CameraInfo{
    Eigen::Matrix4f    transform;
    QString     name;
    int         type;

    float       viewPort_width;
    float       viewPort_height;

    float       tiltAngle;
    float       panAngle;

    float       fov;
    float       near;
    float       far;
};
class ViewPort
{
public:
    ViewPort();

    CameraInfo info;

    void config(float w=1, float h=1);
    virtual void configProjection();
    virtual void configModelView();
    virtual void applyTransform();
    void rotate(float angle, float x, float y, float z);

    virtual Eigen::Vector3f getTranslateFromScreen(float x, float y);
    virtual Eigen::Vector3f getDrawVertexPosition(float x, float y);
};

#endif // VIEWPORT_H
