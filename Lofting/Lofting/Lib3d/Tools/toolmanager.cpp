#include "toolmanager.h"
#include <Tools/tool.h>
#include <Tools/selectTool.h>
#include <Tools/cameratool.h>
#include <Tools/drawtool.h>
#include <Tools/translatetool.h>
#include <Tools/rotatetool.h>
#include <Tools/scaletool.h>
#include <Tools/lofttool.h>

#include <interface.h>
#include <Io/mouse.h>

ToolManager::ToolManager()
{
    hasSelected = false;

}

void ToolManager::setTool(const int i)
{
    currentTool = list.at(i);
}

void ToolManager::start()
{
    list.push_back(new SelectTool());
    list.push_back(new CameraTool());
    list.push_back(new DrawTool());
    list.push_back(new TranslateTool());
    list.push_back(new RotateTool());
    list.push_back(new ScaleTool());
    list.push_back(new LoftTool());
    setTool(Tool::SELECT);
}

bool ToolManager::hasTarget()
{
    return hasSelected;
}

void ToolManager::setTarget(AbstractObj &o)
{
    this->target = &o;
    target->selectObj();
    hasSelected = true;
    Interface::setCurrentSelectList(currentTool->axis.list);
}

void ToolManager::deselect()
{
    if(hasTarget()){
        hasSelected = false;
        getTarget()->deselectObj();
        currentTool->axis.deselectObj();
        Interface::setCurrentSelectList(Interface::displayList);
    }
}

AbstractObj* ToolManager::getTarget()
{
    return target;
}

void ToolManager::mouseMove()
{
    currentTool->mouseMove();
}

void ToolManager::mouseOver()
{
    currentTool->mouseOver();
}

void ToolManager::mouseOut()
{
    currentTool->mouseOut();
}

void ToolManager::mousePress()
{
    currentTool->mousePress();
}

void ToolManager::mouseRelease()
{
    currentTool->mouseRelease();
}

void ToolManager::display()
{
    currentTool->display();
}
