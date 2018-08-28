/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include "exceladapter.h"
#include "linedistribution.h"
#include "paintwx.h"
#include "castinground.h"
#include "target.h"
#include "mount.h"
QT_CHARTS_USE_NAMESPACE



int exedraw(int argc, char *argv[], double vdis, double ydev, double t_width, double t_height, double t_length)
{
	QApplication a(argc, argv);
	exceladapter ea;
	ea.readfile("C:\\CODELIB\\udacity\\udacity\\linechart\\anglelist_32c.xls");

	target tg(vdis, ydev, t_width, t_height, t_length);
	mount mt(1.7, 0, 0.09);
	QList<double> heightlist;
	QList<double> dislist;

	linedistribution ls(ea.stringlist, mt.m_height, mt.m_angle);
	ls.get_heightlist(vdis, heightlist, dislist);

	castinground myci(mt.m_height, mt.anlgeres, ls.getvectorangle());
	PaintWx w(&tg, &mt);

	w.verlist = heightlist;
	w.dislist = dislist;
	w.pcl = myci.Getpcl(mt.m_angle);
	w.pcl_t = myci.GetPclofTarget(mt.m_angle, tg);
	w.show();
	return a.exec();
}


int main(int argc, char *argv[])
{
	exedraw(argc, argv, 5, 5, 10, 1, 5);
	//exedraw(argc,argv,20, 5, 10, 1,  5);
	//exedraw(argc,argv,50, 5, 10, 1,  50);
	//exedraw(argc,argv,100,5, 100,1,  100);
	return 0;
}
