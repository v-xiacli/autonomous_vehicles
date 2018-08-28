#ifndef MOUNT_H
#define MOUNT_H


class mount
{
public:
	mount(mount *out_m)
	{
		m_height = out_m->m_height;
		m_angle = out_m->m_angle;
		anlgeres = out_m->anlgeres;
	}

	mount(double _height, double _angle, double _anlgeres)
	{
		m_height = _height;
		m_angle = _angle;
		anlgeres = _anlgeres;
	}
	double m_height = 1.7;
	double m_angle = 0;
	double anlgeres = 0.09;
};

#endif // MOUNT_H
