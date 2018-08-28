#ifndef CASTINGROUND_H
#define CASTINGROUND_H
#include <QList>
#include <QPointF>
#include "target.h"
#define MAXVALUE 1e10
#define MINVALUE -1e10
typedef QList<QPointF> LINE_ELLIPSE;

class castinground
{
public:
	castinground(double mountheight, double h_angle_res, QList<double> anglelist);
	QList<LINE_ELLIPSE>& Getpcl(double mountangle);
	QList<LINE_ELLIPSE>&GetPclofTarget(double mountangle, target tg);

private:
	double m_height;
	// double mountangle;
	double h_angle_res;
	//  double v_distance;
	QList<double> anglelist;
	LINE_ELLIPSE Calpcl(double cur_angle, double mountangle, double mountheight, double xmin = MINVALUE, double xmax = MAXVALUE, double ymin = MINVALUE, double ymax = MAXVALUE);
	QList<LINE_ELLIPSE> pcl;
	QList<LINE_ELLIPSE> pcl_target;
};

#endif // CASTINGROUND_H
