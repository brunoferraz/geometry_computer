#include "lofttool.h"
#include <interface.h>
#include <QPushButton>
#include <Display/Primitives/basicgeometry.h>
LoftTool::LoftTool()
{
    Interface::canvas->parentWidget()->connect(
                Interface::ui->Loft_apply, &QPushButton::clicked,[=] {
                    emit LoftTool::applyClicked();
    });
    path = nullptr;
}

void LoftTool::mousePress()
{
    SelectTool::mousePress();
    if(Interface::ui->Loft_ShapePick->isChecked()){
        if(Interface::tool.hasTarget()){
            int i = listShapes.indexOf(Interface::tool.getTarget());
            if(i ==-1){
                listShapes.push_back(Interface::tool.getTarget());
                Interface::tool.getTarget()->color << 1, 1, 1, 1;
            }
        }
    }else if(Interface::ui->Loft_PathPick->isChecked()){
        if(Interface::tool.hasTarget()){
            path = Interface::tool.getTarget();
            Interface::tool.getTarget()->color << 1, 1, 1, 1;
        }
    };
}

void LoftTool::applyClicked()
{
   if(listShapes.length()!= 0 && path!=nullptr){
        LoftTool::processShapes();
   }
}

void LoftTool::processShapes()
{
    BasicGeometry g;
}
