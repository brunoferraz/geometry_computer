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
    BasicGeometry *g = new BasicGeometry();
   // CGAL::is_valid(g.P);
    //translate begin shape to start path
    listShapes.at(0)->setPos(path->vertexList.at(0));
    //translate end shape to end path.
    listShapes.at(listShapes.length()-1)->setPos(path->vertexList.at(path->vertexList.length()-1));
    //distribute shapes between begin and end along path
    //adjust shapes rotation based on slope along path

    //get too consecutive shapes
    int a = 0;
    int b = a+1;
    AbstractObj *A = listShapes.at(a);
    AbstractObj *B = listShapes.at(b);

    int i = 0;
    int j = 0;

    Eigen::Vector3f A1 = A->vertexList.at(i);
    //Eigen::Vector3f A2 = A->vertexList.at(i + 1);
    Eigen::Vector3f B1 = B->vertexList.at(j);
    Eigen::Vector3f B2 = B->vertexList.at(j + 1);

    Point_3 p1(A1(0), A1(1), A1(2));
    Point_3 p2(B1(0), B1(1), B1(2));
    Point_3 p3(B2(0), B2(1), B2(2));

//    Halfedge_handle h =
    *g->P.make_triangle(p1, p2, p3);
    //create facets and pass to cgal

    //A1 B1 B2; A1 B2 A2.
    //Ai Bi Bi+1; Ai Bi+1 Ai+1
    //If there isnt Bi + 1, Try Ai+1
    //If there isnt Ai + 1. End Loop

    //Get 2 next Shapes.

    Interface::addChild(*g);

    Interface::canvas->update();
}
