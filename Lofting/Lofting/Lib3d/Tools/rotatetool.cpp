#include "rotatetool.h"
#include <interface.h>
#include <Io/mouse.h>
RotateTool::RotateTool()
{

}

void RotateTool::display()
{
    if(Interface::tool.hasTarget()){
        glPushMatrix();
        glLoadIdentity();
        glMultMatrixf(Interface::tool.target->transform.data());
        axis.display();
        glPopMatrix();
    }
}

void RotateTool::mousePress()
{
    if(Mouse::mouse_left){
        SelectTool::mousePress();
    }else if(Mouse::mouse_middle){
        dragAndDrop = true;
    }
}

void RotateTool::mouseRelease()
{
    dragAndDrop = false;
    axis.xAxis.deselectObj();
    axis.yAxis.deselectObj();
    axis.zAxis.deselectObj();
}

void RotateTool::mouseMove()
{
    if(dragAndDrop){
        if(Interface::tool.hasTarget()){
        Eigen::Vector3f oldPos;
            oldPos << Interface::tool.getTarget()->getX(),
                    Interface::tool.getTarget()->getY(),
                    Interface::tool.getTarget()->getZ();
            Eigen::Vector3f nPos;
            nPos = Interface::view.getTranslateFromScreen(Mouse::velX, Mouse::velY);
            nPos = nPos/100 + oldPos;
            if(axis.xAxis.selected){
                Interface::tool.getTarget()->rotate(Mouse::velY/100, 1, 0, 0);
            }
            if(axis.yAxis.selected){
                Interface::tool.getTarget()->rotate(Mouse::velX/100, 0, 1, 0);
            }
            if(axis.zAxis.selected){
                Interface::tool.getTarget()->rotate(Mouse::velY/100, 0, 0, 1);
            }
        }
    }
}
