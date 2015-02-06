#ifndef LOFTTOOL_H
#define LOFTTOOL_H

#include <Tools/tool.h>
#include <Tools/selectTool.h>
#include <QList>
#include <Display/abstractobj.h>

class LoftTool : public SelectTool
{
public:
    LoftTool();

    QList<AbstractObj *> listShapes;
    AbstractObj *path;

    void mousePress();
    void processShapes();
signals:
    void applyClicked();
};

#endif // LOFTTOOL_H
