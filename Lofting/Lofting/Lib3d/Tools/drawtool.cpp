#include "drawtool.h"
#include "interface.h"
#include <Io/mouse.h>
#include <Display/Primitives/tetrahedron.h>
DrawTool::DrawTool()
{

}

void DrawTool::mousePress()
{
    if(Mouse::mouse_left){
        if(!isDrawing){
            startDraw();
        }else{
            addVertex();
        }
    }else{
        finishDraw();
    }
}

void DrawTool::startDraw()
{
    qDebug() << "iniciando linha";
    isDrawing = true;
    Line *l = new Line();
    line = l;
    l->color << 1, 0, 0, 1;
    Interface::addChild(*l);
    addVertex();
}

void DrawTool::finishDraw()
{
    isDrawing = false;
    line->finishIncremental();
}

void DrawTool::addVertex()
{
    Eigen::Vector3f v;
    v = Interface::view.getDrawVertexPosition(Mouse::x, Mouse::y);
    line->addVertexf(v);
}
