#ifndef PAINTWX_H
#define PAINTWX_H
#include <QWidget>
#include <QList>
#include "castinground.h"


class PaintWx:public QWidget
{
public:
    PaintWx(double target_height,double target_length,double mount_height,double v_distance);
    QList<double> dislist;
    QList<double> verlist;
    QList<LINE_ELLIPSE> pcl;
protected:
    double target_length;
    double target_height;
    double mount_height;
    double v_distance;
    void paintEvent(QPaintEvent *event);    
    void drawpcl(double v_distance);
    void drawv();
};

#endif // PAINTWX_H
