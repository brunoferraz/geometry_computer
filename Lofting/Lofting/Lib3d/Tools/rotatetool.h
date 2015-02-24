#ifndef ROTATETOOL_H
#define ROTATETOOL_H

#include <Tools/tool.h>
#include <Tools/selectTool.h>

class RotateTool : public SelectTool
{
public:
    RotateTool();

    bool dragAndDrop;

    void display();
    void mousePress();
    void mouseRelease();
    void mouseMove();

};

#endif // ROTATETOOL_H
