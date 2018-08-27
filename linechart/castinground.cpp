#include "castinground.h"
#include <math.h>
#include <iostream>
castinground::castinground(double mountheight, double h_angle_res, QList<double> anglelist)
{
    this->mountheight=mountheight;
    this->anglelist=anglelist;
    this->h_angle_res=h_angle_res;
}

LINE_ELLIPSE castinground::Calpcl(double cur_angle,double mountangle)
{
    LINE_ELLIPSE mylist;
    double xstart,xend,xstep;
    double a,b,c;
    double  const  PI   =   acos(double(-1));
    //std::cout<<"mountangle"<<mountangle<<"cur_angle"<<cur_angle<<std::endl;
    cur_angle=cur_angle*PI/180;
    mountangle=mountangle*PI/180;
    //std::cout<<"mountangle"<<mountangle<<"cur_angle"<<cur_angle<<std::endl;
    a=tan(mountangle)*tan(mountangle)-tan(cur_angle)*tan(cur_angle);
    double b1=mountheight*(tan(mountangle)-tan(cur_angle));
    double b2=mountheight*(tan(cur_angle)+tan(mountangle));
    xstart=b1/a;
    xend=b2/a;
    xstep=(xend-xstart)*h_angle_res/180;
    //std::cout<<"xstart"<<xstart<<",xend"<<xend<<",xstep"<<xstep<<std::endl;

    double ma=-1*a;
    double A=tan(cur_angle)*mountheight/ma;
    double A2=A*A;
    double B2=mountheight*mountheight/ma;
    double B=sqrt(B2);
    double C=sqrt(A2-B2);
    double dev=mountheight*tan(mountangle)/ma;
    //double dev=0;

    for(double angle=0;angle<360;angle+=h_angle_res)
    {
        if(A>300||B>300)
        {
            break;
        }
      double x=A*cos(angle)-dev;
      double y=B*sin(angle);

      mylist.append(QPointF(x,y));
     // std::cout<<"x"<<x<<",y"<<y<<std::endl;
    }


    std::cout<<"cur_angle"<<cur_angle<<",mountangle"<<mountangle<<std::endl;
    /*for(double x=xstart;x<=xend;x=x+xstep)
    {
        double y2=pow(mountheight-tan(mountangle)*x,2)-tan(cur_angle)*tan(cur_angle)*x*x;
        double y=sqrt(y2)/tan(cur_angle);
        mylist.append(QPointF(x,y));
        mylist.insert(0,QPointF(x,-1*y));
      //  std::cout<<"x"<<x<<",y"<<y<<std::endl;
    }*/

    return mylist;

}

QList<LINE_ELLIPSE>& castinground::Getpcl(double mountangle)
{
   QList<double>::iterator it=anglelist.begin();
   for(;it!=anglelist.end();it++)
   {
       std::cout<<"*it"<<*it<<std::endl;
       std::cout<<"*mountangle"<<mountangle<<std::endl;
      // if((*it+mountangle)>=0||(*it-mountangle)>=0)
      // {
      //       continue;
      // }

       pcl.append((Calpcl(*it,mountangle)));
   }
    return pcl;
}
