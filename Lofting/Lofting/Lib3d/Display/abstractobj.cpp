#include "abstractobj.h"
#include <interface.h>
AbstractObj::AbstractObj(QObject *parent) :
    QObject(parent)
{
    color << 1, 1,  1,  1;
    selected = false;
    id = 0;
    difuse      <<   1,  1,  1,  1;
    specular    <<   1,  1,  1,  1;
    transform   <<      1,  0,  0,  0,
                        0,  1,  0,  0,
                        0,  0,  1,  0,
                        0,  0,  0,  1;
    shininess = 100;
}

void AbstractObj::display()
{
    glColor4fv(color.data());
    glBegin(GL_POINTS);
    for(int i = 0; i< vertexList.length();i++){
        glVertex3fv(vertexList.at(i).data());
    }
    glEnd();
}

void AbstractObj::selectObj()
{
    selected = true;
}

void AbstractObj::deselectObj()
{
    selected = false;
}

void AbstractObj::mouseOver()
{
    emit OnMouseOver();
}

void AbstractObj::mouseOut()
{
    emit OnMouseOut();
}

void AbstractObj::mousePress()
{
    emit OnMousePress();
}

void AbstractObj::mouseRelease()
{
    emit OnMouseRelease();
}

void AbstractObj::configMaterial()
{
    GLfloat d[4];
    TypeCast::EigenToGLfloat(difuse,d);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, d);
    GLfloat s[4];
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

void AbstractObj::configRender()
{
    glGetBooleanv(GL_LIGHTING, stateLighting);
}

void AbstractObj::desconfigRender()
{
    if(stateLighting[0] == 1){
        glEnable(GL_LIGHTING);
    }else{
        glDisable(GL_LIGHTING);
    }
}

void AbstractObj::configTransform()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glMultMatrixf(transform.data());
}

void AbstractObj::desconfigTransform()
{
    glPopMatrix();
}

void AbstractObj::namePolyhedron()
{
    glColor4fv(TypeCast::indexToColor(id).data());
}

void AbstractObj::setPos(float _x, float _y, float _z)
{
    transform(0, 3) = _x;
    transform(1, 3) = _y;
    transform(2, 3) = _z;
}
void AbstractObj::setPos(Eigen::Vector3f v)
{
    transform(0, 3) = v(0);
    transform(1, 3) = v(1);
    transform(2, 3) = v(2);
}

void AbstractObj::rotate(float angle, float _x, float _y, float _z)
{
    //Change global transform matrix
    Eigen::Matrix3f S;
    S << 0,     -_z,     _y,
         _z,     0,      -_x,
         -_y,    _x,      0;
    Eigen::Vector3f u;
    u << _x, _y , _z;
    u.normalize();

    Eigen::Matrix3f uut;
    uut = u * u.transpose();
    Eigen::Matrix3f I;
    I <<    1,  0,  0,
            0,  1,  0,
            0,  0,  1;

    Eigen::Matrix3f M;
    M = uut + cos(angle) * (I - uut) + sin(angle) * S;
    Eigen::Matrix4f R;
    R << M(0, 0),   M(0, 1),    M(0, 2),    0,
         M(1, 0),   M(1, 1),    M(1, 2),    0,
         M(2, 0),   M(2, 1),    M(2, 2),    0,
               0,         0,          0,    1;
    transform = transform * R;
}

void AbstractObj::rotate(Eigen::Vector4f v)
{
    //Change global transform matrix
    Eigen::Matrix3f S;
    S << 0,     -v(3),     v(2),
         v(3),     0,      -v(1),
         -v(2),    v(1),      0;
    Eigen::Vector3f u;
    u << v(1), v(2) , v(3);
    u.normalize();

    Eigen::Matrix3f uut;
    uut = u * u.transpose();
    Eigen::Matrix3f I;
    I <<    1,  0,  0,
            0,  1,  0,
            0,  0,  1;

    Eigen::Matrix3f M;
    M = uut + cos(v(0)) * (I - uut) + sin(v(0)) * S;
    Eigen::Matrix4f R;
    R << M(0, 0),   M(0, 1),    M(0, 2),    0,
         M(1, 0),   M(1, 1),    M(1, 2),    0,
         M(2, 0),   M(2, 1),    M(2, 2),    0,
               0,         0,          0,    1;
    transform = transform * R;
}

float AbstractObj::getX()
{
    return transform(0, 3);
}

float AbstractObj::getY()
{
    return transform(1, 3);
}

float AbstractObj::getZ()
{
    return transform(2, 3);
}
