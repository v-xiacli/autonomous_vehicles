#ifndef PAINTWX_H
#define PAINTWX_H
#include <QWidget>
#include <QList>
#include "castinground.h"
#include "target.h"
#include "mount.h"

class PaintWx:public QWidget
{
public:
    PaintWx(target * _tg,mount *_mt);
    QList<double> dislist;
    QList<double> verlist;
    QList<LINE_ELLIPSE> pcl;
    QList<LINE_ELLIPSE> pcl_t;
protected:
    double target_length;
    double target_height;
    double mount_height;
    double v_distance;
    target *ptg;
    mount *pmt;
    void paintEvent(QPaintEvent *event);    
    void drawpcl(double v_distance);
    void drawv();
};

#endif // PAINTWX_H
