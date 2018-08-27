#ifndef CASTINGROUND_H
#define CASTINGROUND_H
#include <QList>
#include <QPointF>
typedef QList<QPointF> LINE_ELLIPSE;

class castinground
{
public:
    castinground(double mountheight,double h_angle_res,  QList<double> anglelist);
    QList<LINE_ELLIPSE>& Getpcl(double mountangle);

private:
    double mountheight;
  // double mountangle;
    double h_angle_res;
    double v_distance;
    QList<double> anglelist;
    LINE_ELLIPSE Calpcl(double cur_angle,double mountangle);
    QList<LINE_ELLIPSE> pcl;
};

#endif // CASTINGROUND_H
