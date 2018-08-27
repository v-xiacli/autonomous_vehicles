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

   // if(cur_angle>=0)
    {
   //       return mylist;
    }

    if((cur_angle-mountangle)>=0)
    {
        return mylist;
    }

    double xstart,xend,xstep;
    double a,b,c;
    double  const  PI   =   acos(double(-1));
    double beta=-1*cur_angle*PI/180.0;
    double alpha=mountangle*PI/180.0;
    double h=mountheight;
    a=tan(beta)*tan(beta)-tan(alpha)*tan(alpha);
    double A=fabs(tan(beta)*h/a);
    double A2=A*A;
    double B2=h*h/a;
    double dev=mountheight*tan(alpha)/a;
    double B,C;
    double x, y;
    for(double angle=0;angle<360;angle+=h_angle_res)
    {

        if(B2>0)
        {
            B=sqrt(B2);
            x=A*cos(angle*PI/180)-dev;
            y=B*sin(angle*PI/180);
            mylist.append(QPointF(x,y));
        }
        else if(B2<0&&cur_angle<0)
        {
            B=sqrt(0-B2);
            x=-1*fabs(A/cos(angle*PI/180))-dev;
            y=-1*(B*tan(angle*PI/180));
            mylist.append(QPointF(x,y));
            if(angle==0)
            {
                  std::cout<< "cur_angle"<<cur_angle<<"x"<<x<<"y"<<y<< std::endl;
            }

        }
        else if(B2<0&&cur_angle>=0)
        {
            B=sqrt(0-B2);
            x=fabs(A/cos(angle*PI/180))-dev;
            y=(B*tan(angle*PI/180));
            mylist.append(QPointF(x,y));
            if(angle==0)
            {
                  std::cout<< "cur_angle"<<cur_angle<<"x"<<x<<"y"<<y<< std::endl;
            }

        }

    }


   // std::cout<<"cur_angle"<<cur_angle*180/PI<<",mountangle"<<mountangle<<std::endl;
   /* for(double x=xstart;x<=xend;x=x+xstep)
    {
        double y2=pow(mountheight-tan(mountangle)*x,2)-tan(cur_angle)*tan(cur_angle)*x*x;
        double y=sqrt(y2)/tan(cur_angle);
        mylist.append(QPointF(x,y));
        mylist.insert(0,QPointF(x,-1*y));
      //  std::cout<<"x"<<x<<",y"<<y<<std::endl;
    }
*/
    return mylist;

}

QList<LINE_ELLIPSE>& castinground::Getpcl(double mountangle)
{
   QList<double>::iterator it=anglelist.begin();
   for(;it!=anglelist.end();it++)
   {
      // if((*it+mountangle)>=0||(*it-mountangle)>=0)
      // {
      //       continue;
      // }

       pcl.append((Calpcl(*it,mountangle)));
   }
    return pcl;
}
