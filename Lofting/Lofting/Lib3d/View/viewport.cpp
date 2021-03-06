#include "viewport.h"
#include <Util/typecast.h>

ViewPort::ViewPort()
{
    info.fov        = 60;
    info.near       = 0.1;
    info.far        = 100;
    info.transform <<   1,  0,  0,  0,
                        0,  1,  0,  0,
                        0,  0,  1,  -3,
                        0,  0,  0,  1;


}

void ViewPort::config(float w, float h)
{
    if(h!=1 && w!=1){
        info.viewPort_height = h;
        info.viewPort_width  = w;
    }
    glViewport(0, 0, info.viewPort_width, info.viewPort_height);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    configProjection();
    applyTransform();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    configModelView();
}

void ViewPort::configProjection()
{
    float ratio     = info.viewPort_width/info.viewPort_height;
    gluPerspective(info.fov, ratio, info.near, info.far);
}

void ViewPort::configModelView()
{

}

void ViewPort::applyTransform()
{
    GLfloat v[16];
    TypeCast::EigenMatrixToGlMatrixF(info.transform, v);
    glMultMatrixf(v);
    glRotatef(40, 1, 1, 0);
    glGetFloatv(GL_PROJECTION_MATRIX, v);
    TypeCast::GlMatrixFToEigenMatrix(v, info.transform);
}

void ViewPort::rotate(float angle, float x, float y, float z)
{
    glMatrixMode(GL_PROJECTION);
    glRotatef(angle, x, y, z);
    glMatrixMode(GL_MODELVIEW);
}

Eigen::Vector3f ViewPort::getTranslateFromScreen(float x, float y)
{
    Eigen::Vector3f nPos;
    nPos << x, -y, y;
    return nPos;
}

Eigen::Vector3f ViewPort::getDrawVertexPosition(float x, float y)
{
    Eigen::Vector3f nPos;
    float ratio = info.viewPort_width/info.viewPort_height;
    float nx = ratio *( 2* x - info.viewPort_width)/info.viewPort_width;
    float ny = (2 * y - info.viewPort_height)/info.viewPort_height;
    nPos << nx, ny, 0;
    return nPos;
}
