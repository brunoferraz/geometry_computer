#include "grahamlist.h"

GrahamList::GrahamList()
{
    maxX = 0;
    maxY = 0;
}

void GrahamList::addPoint(Vector4d &p)
{
    if(!list.isEmpty()){
        if(p(0) > list.at(maxX)(0)){
            maxX = list.length();
        }
        if(p(1) > list.at(maxY)(1)){

            maxY = list.length();
        }
    }
    GrahamList::list.push_back(p);
}

void GrahamList::orderByAngle()
{
    Vector4d vb;
    vb << 1, 0, 0, 0;
    for(int i=0; i < list.length(); i ++)
    {
        if(maxY != i){
            Vector4d v;
            v = list.at(i) - list.at(maxY);
            v.normalize();
            double angle = std::acos(vb.dot(v))*180/3.14;
            Vector4d vf;
            vf << list.at(i)(0), list.at(i)(1), list.at(i)(2), angle;
            list.replace(i, vf);
        }
    }
    qSort(list.begin(), list.end(), Util::toAssendingVector4d_W);
    for(int i=0; i < list.length(); i ++)
    {
        Vector4d vf;
        vf << list.at(i)(0), list.at(i)(1), list.at(i)(2), 0;
        list.replace(i, vf);
    }
    maxY = 0;
}

void GrahamList::findConvexHull()
{
    orderByAngle();
        Vector3d a;
        Vector3d b;
        convexHull.push_back(list.at(0));
        convexHull.push_back(list.at(1));
        for(int i= 1; i < list.length(); i++){
            int nextIndex = i+1;
            if(nextIndex>=list.length()) nextIndex = 0;
            Vector4d next = list.at(nextIndex);
            Vector4d current = convexHull.at(convexHull.length() -1);
            Vector4d last = convexHull.at(convexHull.length() -2);

            double orientation = Util::orientation(last,current,next);
            if(orientation>0){
                while(orientation>0){
                    current = convexHull.at(convexHull.length() -1);
                    last = convexHull.at(convexHull.length() -2);
                    orientation = Util::orientation(last,current,next);
                    if(orientation>0){
                        convexHull.pop_back();

                    }
                 }
            }
            convexHull.push_back(next);
        }
}
