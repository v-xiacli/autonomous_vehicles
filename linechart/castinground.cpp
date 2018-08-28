#include "castinground.h"
#include <math.h>
#include <iostream>
castinground::castinground(double mountheight, double h_angle_res, QList<double> anglelist)
{
	this->m_height = mountheight;
	this->anglelist = anglelist;
	this->h_angle_res = h_angle_res;
}

LINE_ELLIPSE castinground::Calpcl(double cur_angle, double mountangle, double o_mountheight, double xmin, double xmax, double ymin, double ymax)
{

	LINE_ELLIPSE mylist;

	if ((cur_angle - mountangle) >= 0)
	{
		return mylist;
	}

	double a;
	double  const  PI = acos(double(-1));
	double beta = -1 * cur_angle*PI / 180.0;
	double alpha = mountangle * PI / 180.0;
	double h = o_mountheight;
	a = tan(beta)*tan(beta) - tan(alpha)*tan(alpha);
	double A = fabs(tan(beta)*h / a);
	double B2 = h * h / a;
	double dev = o_mountheight * tan(alpha) / a;
	double B;
	double x, y;
	//std::cout<< "h"<<h<<std::endl;
	std::cout << "xmin" << xmin << "xmax" << xmax << "ymin" << ymin << "ymax" << ymax << std::endl;
	for (double angle = 0;angle < 360;angle += h_angle_res)
	{

		if (B2 > 0)
		{
			B = sqrt(B2);
			x = A * cos(angle*PI / 180) - dev;
			y = B * sin(angle*PI / 180);

		}
		else if (B2 < 0 && cur_angle < 0)
		{
			B = sqrt(0 - B2);
			x = -1 * fabs(A / cos(angle*PI / 180)) - dev;
			y = -1 * (B*tan(angle*PI / 180));
			if (angle == 0)
			{
				std::cout << "cur_angle" << cur_angle << "x" << x << "y" << y << std::endl;
			}

		}
		else if (B2 < 0 && cur_angle >= 0)
		{
			B = sqrt(0 - B2);
			x = fabs(A / cos(angle*PI / 180)) - dev;
			y = (B*tan(angle*PI / 180));
			if (angle == 0)
			{
				std::cout << "cur_angle" << cur_angle << "x" << x << "y" << y << std::endl;
			}

		}
		else
		{
			continue;
		}

		if (x > xmax || x < xmin)
		{
			continue;
		}

		if (y > ymax || y < ymin)
		{
			continue;
		}

		mylist.append(QPointF(x, y));

	}

	return mylist;

}

QList<LINE_ELLIPSE>& castinground::Getpcl(double mountangle)
{
	QList<double>::iterator it = anglelist.begin();
	for (;it != anglelist.end();it++)
	{
		pcl.append((Calpcl(*it, mountangle, this->m_height)));
		std::cout << "pcl" << pcl.size() << std::endl;
	}
	return pcl;
}

QList<LINE_ELLIPSE>& castinground::GetPclofTarget(double mountangle, target tg)
{
	QList<double>::iterator it = anglelist.begin();
	LINE_ELLIPSE temp;
	for (;it != anglelist.end();it++)
	{
		temp = (Calpcl(*it, mountangle, (this->m_height - tg.height), tg.distance, tg.distance + tg.length, tg.ydev - 1 * tg.width / 2, tg.ydev + tg.width / 2));
		//temp=(Calpcl(*it,mountangle,(this->m_height-targetheight)));
		pcl_target.append(temp);
		if (temp.size() > 0)
			std::cout << "temp" << temp.size() << std::endl;
	}
	return pcl_target;
}
