#ifndef TARGET_H
#define TARGET_H


class target
{
public:
    target(target * out_t)
    {
        ydev=out_t->ydev;
        distance=out_t->distance;
        width=out_t->width;
        height=out_t->height;
        length=out_t->length;
    }

    target(double _distance,double _ydev,double _width,double _height,double _length)
    {
        this->distance=_distance;
        this->width=_width;
        this->height=_height;
        this->length=_length;
        this->ydev=_ydev;
    }

    double ydev;
    double distance;
    double width;
    double height;
    double length;
};

#endif // TARGET_H
