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
QT_CHARTS_USE_NAMESPACE



int exedraw(int argc, char *argv[],double t_height, double t_length, double vdis)
{ QApplication a(argc, argv);
    exceladapter ea;
    ea.readfile("C:\\CODELIB\\udacity\\udacity\\linechart\\anglelist_32e.xls");
    double m_height=1.8;
    double m_angle=0;
    double anlgeres=0.27;
    linedistribution ls(ea.stringlist,m_height,m_angle);
    QList<double> heightlist;
    QList<double> dislist;
    ls.get_heightlist(vdis,heightlist,dislist);    
    castinground myci(m_height,anlgeres,ls.getvectorangle());

    PaintWx w(t_height,t_length,m_height,vdis);
    w.verlist=heightlist;
    w.dislist=dislist;
    w.pcl=myci.Getpcl(m_angle);
    w.show();
    return a.exec();
}


int main(int argc, char *argv[])
{

      exedraw(argc,argv,0.5, 0.3, 5);
      exedraw(argc,argv,1.5, 1, 20);
      exedraw(argc,argv,1.5, 1, 50);
      return exedraw(argc,argv,1.5, 1, 100);
/*
//![1]
    QLineSeries *series = new QLineSeries();
//![1]

//![2]
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
//![2]

//![3]
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");
//![3]

//![4]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![4]


//![5]
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
//![5]
*/

}
