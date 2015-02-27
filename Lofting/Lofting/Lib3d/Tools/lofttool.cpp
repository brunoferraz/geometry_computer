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
//        LoftTool::processShapes();
        LoftTool::processShapes2();
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
        int b = a +1;
        AbstractObj *A = listShapes.at(a);
        AbstractObj *B = listShapes.at(b);

        int i = 0;
        int j = 0;
        float bigger = std::max(A->vertexList.length(), B->vertexList.length());
        for(int k = 0; k < bigger; k ++){
            i++;
            j++;
            if(i +1> A->vertexList.length()-1) i--;
            if(j +1> B->vertexList.length()-1) j--;

            A->getVertexList4f();
            B->getVertexList4f();

            Eigen::Vector4f A1 = A->transform * A->vertexList4f.at(i);
            Eigen::Vector4f A2 = A->transform * A->vertexList4f.at(i + 1);

            Eigen::Vector4f B1 = B->transform * B->vertexList4f.at(j);
            Eigen::Vector4f B2 = B->transform * B->vertexList4f.at(j + 1);

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

void LoftTool::processShapes2()
{
    BasicGeometry *g = new BasicGeometry();
    // CGAL::is_valid(g.P);
     //translate begin shape to start path
    Interface::addChild(*g);
    g->color << 1, 0.5, 0, 1;
    g->shininess = 20;
    //    listShapes.at(0)->setPos(-1, -1, -1);
    //translate end shape to end path.
    listShapes.at(0)->setPos(path->vertexList.at(0));

    listShapes.at(listShapes.length()-1)->setPos(path->vertexList.at(path->vertexList.length()-1));
    //distribute shapes between begin and end along path
        if(listShapes.length() > 2){
            //sum all vectors size from path
            float sum =0;
            QList<float> sizes;
            QList<Eigen::Vector3f> diffList;
            for(int i = 1 ; i < path->vertexList.length(); i ++){
                Eigen::Vector3f diff = path->vertexList.at(i) - path->vertexList.at(i-1);
                diffList.push_back(diff);
//                std::cout << diff.transpose() << std::endl;
                float norm = diff.norm();
                sum += norm;
                sizes.push_back(norm);
            }
            QList <AbstractObj *> listShapesToPos;
            //get how many shapes you need to distribute
            for(int i = 1; i < listShapes.length()-1; i++){
                listShapesToPos.push_back(listShapes.at(i));
            }
            float part      = sum / (path->vertexList.length()-1);
            //discover between each path vectors shape must be
            int k = 0;
            while(listShapesToPos.length()){
                AbstractObj *shape;
                k++;
                if(!listShapesToPos.isEmpty()){
                    shape = listShapesToPos.takeFirst();
                    int next = 0;
                    float walked    = 0; //partial sum of vectors norm till current pos
                    for(int j = next; j < sizes.length(); j++){
                        walked += sizes.at(j);
                        if(walked > part * k){
                            std::cout << diffList.at(j).transpose() << std::endl;
                            shape->setPos(diffList.at(j));//qDebug() << walked << "  " << part * k;
                            next = j;
                            break;
                        }
                    }
                }
            }
        }
    //adjust shapes rotation based on slope along path
    //get too consecutive shapes
    for(int a=0; a< listShapes.length()-1; a++){
        int b = a +1;
        listShapes.at(a)->getVertexList4f();
        listShapes.at(b)->getVertexList4f();
        QList<Eigen::Vector4f> A;
        QList<Eigen::Vector4f> B;
        AbstractObj *Ao;
        AbstractObj *Bo;
        //A is alwais bigger
        bool flipFacet = false;
        if(listShapes.at(a)->vertexList4f.length() >= listShapes.at(b)->vertexList4f.length()){
            flipFacet = true;
            Ao = listShapes.at(a);
            Bo = listShapes.at(b);
            A = Ao->vertexList4f;
            B = Bo->vertexList4f;
        }else{
            flipFacet = false;
            Ao = listShapes.at(b);
            Bo = listShapes.at(a);
            A = Ao->vertexList4f;
            B = Bo->vertexList4f;
        }
        int ratio = A.length()/B.length();
        int loops = max(A.length(), B.length()) +1;
        int counter = ratio;
        bool side = true;
        bool last = false;
        while(loops){

            int Apos, Bpos;
            Apos = 0;
            Bpos = 0;
            if(A.length() >=1) Apos = A.length()-1;
            if(B.length() >=1) Bpos = B.length()-1;
            QList<Eigen::Vector4f> l;
            if(side){
                l.push_back(Ao->transform * A.at(Apos));
                l.push_back(Bo->transform * B.at(Bpos));
                if(Apos>0)Apos--;
                l.push_back(Ao->transform * A.at(Apos));
                if(A.length()>1){
                    A.pop_back();
                }
                counter--;
                if(counter == 0){
                    side = !side;
                    counter=ratio;
                }
            }else{
                l.push_back(Ao->transform * A.at(Apos));
                l.push_back(Bo->transform * B.at(Bpos));
                if(Bpos>0)Bpos--;
                l.push_back(Bo->transform * B.at(Bpos));

                if(B.length()>1){
                    B.pop_back();
                }
                side= !side;
            }
            if(flipFacet){
                l.swap(0,1);
            }
            Point_3 p1(l.at(0)(0),l.at(0)(1),l.at(0)(2));
            Point_3 p2(l.at(1)(0),l.at(1)(1),l.at(1)(2));
            Point_3 p3(l.at(2)(0),l.at(2)(1),l.at(2)(2));

            Build_triangle<Polyhedron::HalfedgeDS> triangle(p1, p2, p3);
            g->P.delegate(triangle);

            if(last) loops = 0;
            if(A.length() <=1 && B.length() <=1) last = true;


        }
        Interface::canvas->update();
    }
}

AbstractObj* LoftTool::changeSide(AbstractObj *A, AbstractObj *B, bool &side)
{
    AbstractObj *P;
    if(side){
        P = A;
    }else{
        P = B;
    }
    return P;
}
