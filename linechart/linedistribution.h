#ifndef LINEDISTRIBUTION_H
#define LINEDISTRIBUTION_H
#include <QList>

class linedistribution
{
public:
    linedistribution(QList<QString> & vectorangle,double mountheight,double mountangle);
    void get_heightlist( double v_distance,  QList<double> &heightlist,  QList<double> &dislist);
    QList<double> getvectorangle(){
        return this->vectorangle;
    }

private:
    double mountheight;
    double mountangle;
    double v_distance;
    QList<double> vectorangle;
    QList<double> heightlist;

};

#endif // LINEDISTRIBUTION_H
