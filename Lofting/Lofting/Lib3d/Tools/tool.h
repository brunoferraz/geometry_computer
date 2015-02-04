#ifndef TOOL_H
#define TOOL_H
#include <QDebug>
#include <Display/abstractobj.h>
#include <Display/UiElements/axis3d.h>
#include <QList>

class Tool
{
public:
    Tool();
    static int const SELECT     = 0;
    static int const CAMERA     = 1;
    static int const DRAW       = 2;
    static int const TRANSLATE  = 3;
    static int const ROTATE     = 4;
    static int const SCALE      = 5;
    static int const LOFT       = 6;

    int type;
    Axis3d axis;
    AbstractObj *target;

    virtual void mouseOver();
    virtual void mouseOut();
    virtual void mousePress();
    virtual void mouseRelease();
    virtual void mouseMove();

    virtual void display();
};

#endif // TOOL_H
