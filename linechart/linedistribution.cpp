#include "linedistribution.h"
#include <iostream>
#include <math.h>
linedistribution::linedistribution(QList<QString> & vectorangles, double mountheight, double mountangle)
{
	this->mountheight = mountheight;
	this->mountangle = mountangle;

	QList<QString>::iterator it = vectorangles.begin();
	std::cout << "---------------";
	for (; it != vectorangles.end(); it++)
	{
		double vecvalue = it->toDouble();
		vectorangle.append(vecvalue);
		std::cout << vecvalue << std::endl;
	}
}


void linedistribution::get_heightlist(double v_distance, QList<double> &heightlist, QList<double> &dislist)
{
	double  const  PI = acos(double(-1));
	QList<double>::iterator it = vectorangle.begin();
	for (; it != vectorangle.end(); it++)
	{
		double lineheight = mountheight + v_distance * tan((*it - mountangle)*PI / 180);
		heightlist.append(lineheight);

		if (*it >= 0)
		{
			continue;
		}

		double dis = -1 * mountheight / tan((*it - mountangle)*PI / 180);
		dislist.append(dis);
	}
	/*
		for ( QList<double>::iterator it=heightlist.begin(); it != heightlist.end(); it++)
		{
			std::cout<<"height"<<"---("<<*it<<")"<<std::endl;
		}

		for ( QList<double>::iterator it=dislist.begin(); it != dislist.end(); it++)
		{
			std::cout<<"dis"<<"---("<<*it<<")"<<std::endl;
		}
	*/
	//return dislist;
}
