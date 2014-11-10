#include "convexhull.h"

ConvexHull::ConvexHull()
{

}

void ConvexHull::addPoint(Vector4d &p)
{
//    if(!list.isEmpty()){
//        if(p(0) > list.at(maxX)(0)){
//            maxX = list.length();
//        }
//        if(p(1) > list.at(maxY)(1)){

//            maxY = list.length();
//        }
//    }
//    ConvexHull::list.push_back(p);
}

QList<Vector4d> ConvexHull::orderByAngle(QList<Vector4d> &list)
{
    Vector4d vb;
    vb << 1, 0, 0, 0;
    int maxX = 0;
    int maxY = 0;
    for(int i=0; i < list.length(); i ++)
    {
        if(!list.isEmpty()){
            if(list.at(i)(0) > list.at(maxX)(0)){
                maxX = i;
            }
            if(list.at(i)(1) > list.at(maxY)(1)){

                maxY = i;
            }
        }
    }
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
    for(int i=2; i < list.length(); i ++)
    {
        Vector4d a = list.at(i);
        Vector4d b = list.at(i-1);
        Vector4d c = list.at(i-2);
        Vector4d v1 = b-c;
        v1.normalize();
        Vector4d v2 = a-b;
        v2.normalize();
        double cosa = v1.dot(v2);
        if(cosa == 0 || cosa == 180){
            qDebug()<< "Coplanares";
        }
    }
    for(int i=0; i < list.length(); i ++)
    {
        Vector4d vf;
        vf << list.at(i)(0), list.at(i)(1), list.at(i)(2), 0;
        list.replace(i, vf);
    }
    maxY = 0;
    return list;
}

QList<Vector4d> ConvexHull::findConvexHull(QList<Vector4d> &plist)
{
        QList<Vector4d> list;
        list = orderByAngle(plist);
        QList<Vector4d> convexHull;
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
            if(orientation>=0){
                int counter = 0;
                while(orientation>=0){
                    counter++;
                    orientation = -1; // Break the loop if didnt enter on if
                    if(convexHull.length()>1){
                        current = convexHull.at(convexHull.length() -1);
                        last = convexHull.at(convexHull.length() -2);
                        orientation = Util::orientation(last,current,next);
                        if(orientation>=0){
                            if(!convexHull.isEmpty()){
                                convexHull.pop_back();
                            }
                        }
                    }else{
                       qDebug()<< "end list<<<" << convexHull.length() << " <<< ";
                       qDebug()<< orientation;
                       qDebug()<< "end list";
                       orientation = -1;
                    }
                    if(counter>list.length()*100){
                        qDebug()<< "trapped in while <<<" << convexHull.length() << " <<< ";
                        qDebug()<< orientation;
                        orientation = -1;
                        qDebug()<< "trapped in while";
                    }
                 }
            }
            convexHull.push_back(next);
        }
        return convexHull;
}

QList<QList<Vector4d>> divideAndConquer(QList<Vector4d> &list)
{
    QList<QList<Vector4d>>polygonList;

    return polygonList;
}
