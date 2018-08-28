#ifndef TARGET_H
#define TARGET_H
#include <iostream>
using namespace std;

class target
{
public:
	target(target * out_t)
	{
		ydev = out_t->ydev;
		distance = out_t->distance;
		width = out_t->width;
		height = out_t->height;
		length = out_t->length;
	}

	target(double _distance, double _ydev, double _width, double _height, double _length)
	{
		this->distance = _distance;
		this->width = _width;
		this->height = _height;
		this->length = _length;
		this->ydev = _ydev;
	}

    friend ostream& operator<<(ostream& output,target * c)
    {
      output<<"distance "<<c->distance<<",width "<<c->width<<",height "<<c->height<<",length "<<c->length<<",ydev "<<c->ydev;
      return output;
    }

	double ydev;
	double distance;
	double width;
	double height;
	double length;
};

#endif // TARGET_H
