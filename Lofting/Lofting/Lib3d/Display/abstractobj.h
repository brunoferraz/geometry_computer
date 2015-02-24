#ifndef ABSTRACTOBJ_H
#define ABSTRACTOBJ_H

#include <QObject>
#include <QList>
#include <Eigen/Dense>
#include <GL/gl.h>
#include <QDebug>
#include <Util/typecast.h>

class AbstractObj : public QObject
{
    Q_OBJECT
public:
    explicit AbstractObj(QObject *parent = 0);

    int                 id;
    Eigen::Matrix4f     transform;
    Eigen::Vector4f     color;
    Eigen::Vector4f     difuse;
    Eigen::Vector4f     specular;
    float               shininess;

    QList<AbstractObj *>    displayList;
    QList<Eigen::Vector3f>  vertexList;
    QList<Eigen::Vector4f>  vertexList4f;

    GLboolean stateLighting[1];

    virtual void display();

    bool selected;
    void selectObj();
    void deselectObj();

    virtual void mouseOver();
    virtual void mouseOut();
    virtual void mousePress();
    virtual void mouseRelease();

    virtual void configMaterial();

    virtual void configRender();
    virtual void desconfigRender();

    virtual void configTransform();
    virtual void desconfigTransform();

    virtual void namePolyhedron();

    virtual void setPos(float _x, float _y, float _z);
    virtual void setPos(Eigen::Vector3f v);

    virtual void rotate(float angle, float _x, float _y, float _z);
    virtual void rotate(Eigen::Vector4f v);

    inline virtual Eigen::Vector3f getPos(){
        Eigen::Vector3f v;
        v<< this->getX(), this->getY(), this->getZ();
        return v;
    }
    inline virtual QList<Eigen::Vector4f>getVertexList4f(){
        if(vertexList.length() > 0){
            vertexList4f.clear();
            for(int i = 0; i < vertexList.length(); i++){
                Eigen::Vector4f v;
                v << vertexList.at(i)(0), vertexList.at(i)(1), vertexList.at(i)(2), 1;
                vertexList4f.push_back(v);
            }
        }
        return vertexList4f;
    }
    float getX();
    float getY();
    float getZ();

private:
    bool isMouseOver;
    bool isMouseOut;
    bool isMousePress;

signals:
    void OnMouseOver();
    void OnMouseOut();
    void OnMousePress();
    void OnMouseRelease();
public slots:

};

#endif // ABSTRACTOBJ_H
