#ifndef TOOLMANAGER_H
#define TOOLMANAGER_H

#include <Display/abstractobj.h>
#include <QList>
#include <Tools/tool.h>

class ToolManager
{
public:
    ToolManager();

    Tool *currentTool;
    void setTool(int const i);
    int _tool;
    inline int getTool() {return _tool;}
    QList<Tool *> list;

    AbstractObj *target;

    void start();

    bool hasTarget();
    void setTarget(AbstractObj &o);
    void deselect();
    AbstractObj* getTarget();

    void mouseMove();
    void mouseOver();
    void mouseOut();
    void mousePress();
    void mouseRelease();

    void display();
private:
    bool hasSelected;
};

#endif // TOOLMANAGER_H
