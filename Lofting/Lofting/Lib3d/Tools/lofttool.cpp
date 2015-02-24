#include "lofttool.h"
#include <interface.h>
#include <QPushButton>
#include <Display/Primitives/basicgeometry.h>
#include <Display/Primitives/tetrahedron.h>
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
//    listShapes.at(0)->setPos(-1, -1, -1);
    //translate end shape to end path.
    listShapes.at(listShapes.length()-1)->setPos(path->vertexList.at(path->vertexList.length()-1));
    //distribute shapes between begin and end along path
    //adjust shapes rotation based on slope along path

    //get too consecutive shapes
    for(int a=0; a< listShapes.length()-1; a++){
        //int a = 0;
        int b = a +1;
        AbstractObj *A = listShapes.at(a);
        AbstractObj *B = listShapes.at(b);

        //int i = 0;

        for(int i; i < A->vertexList.length()-1; i ++){
        int j = i;

            A->getVertexList4f();
            B->getVertexList4f();

            Eigen::Vector4f A1 = A->transform * A->vertexList4f.at(i);
            Eigen::Vector4f A2 = A->transform * A->vertexList4f.at(i + 1);

            Eigen::Vector4f B1 = B->transform * B->vertexList4f.at(j);
            Eigen::Vector4f B2 = B->transform * B->vertexList4f.at(j + 1);

//            std::cout << A->transform << endl;
//            std::cout << A1.transpose() << std::endl;
//            std::cout << A2.transpose() << std::endl;
//            std::cout << B1.transpose() << std::endl;
//            std::cout << B2.transpose() << std::endl;

            Point_3 p1(A1(0), A1(1), A1(2));
            Point_3 p2(B1(0), B1(1), B1(2));
            Point_3 p3(B2(0), B2(1), B2(2));
            Point_3 p4(A2(0), A2(1), A2(2));


            Build_triangle<Polyhedron::HalfedgeDS> triangle(p1, p2, p3);
            g->P.delegate(triangle);
            Build_triangle<Polyhedron::HalfedgeDS> triangle2(p1, p3, p4);
            g->P.delegate(triangle2);

        }
        //create facets and pass to cgal

        //A1 B1 B2; A1 B2 A2.
        //Ai Bi Bi+1; Ai Bi+1 Ai+1
        //If there isnt Bi + 1, Try Ai+1
        //If there isnt Ai + 1. End Loop

        //Get 2 next Shapes.
    }

    Interface::addChild(*g);
    g->color << 1, 0.5, 0, 1;
    g->shininess = 20;

    Tetrahedron *t = new Tetrahedron();
    t->setPos(0, 0, 0);
    t->color << 1, 0, 1, 1;
    t->shininess = 20;
    //Interface::addChild(*t);

    Interface::canvas->update();
}
