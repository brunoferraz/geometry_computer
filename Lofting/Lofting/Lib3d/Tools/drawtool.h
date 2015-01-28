#ifndef DRAWTOOL_H
#define DRAWTOOL_H
#include <Tools/tool.h>
#include <Display/Primitives/line.h>

class DrawTool : public Tool
{
public:
    DrawTool();
    bool isDrawing;
    void mousePress();

    Line *line;

    void startDraw();
    void finishDraw();

    void addVertex();
};

#endif // DRAWTOOL_H
