#include <iostream>
#include <cmath>
#include <stdio.h>
#include <math.h>

# define M_PI           3.14159265358979323846
# define eps 1e-5
using namespace std;

class point
{
public:
	float x, y;
public:
	point();
	point(float m_x, float m_y);
	~point();

private:
	
};

point::point()
{
	x = 0;
	y = 0;
}

point::point(float m_x, float m_y)
{
	x = m_x;
	y = m_y;
}

point::~point()
{
}

class line
{
public:
	float a, b, c;

public:
	line(float m_a, float m_b, float m_c);
	line(point p1, point p2);
	~line();

private:

};

line::line(float m_a, float m_b, float m_c)
{
	a = m_a;
	b = m_b;
	c = m_c;
}

line::~line()
{
}

line::line(point p1, point p2)
{
	a = p2.y - p1.y;
	b = p1.x - p2.x;
	c = (p2.x*p1.y - p1.x*p2.y);
}


class circle
{
public:
	circle();
	void get_point(point m_center);
	void get_radius(float m_radius);
	~circle();

public:
	point center;
	float radius;

};

circle::circle()
{
	center = point(0, 0);
	radius = 1;
};

void circle::get_point(point m_center)
{
	center = m_center;
};

void circle::get_radius(float m_radius)
{
	radius = m_radius;
}
circle::~circle()
{
};


float distance_point_to_point(point &p1, point &p2);
float distance_point_to_line(point &p, line &l);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int number_test_case;
	cin >> number_test_case;
	circle c;
	c.get_point(point(0, 0));
	while (number_test_case)
	{
		
		number_test_case--;
	}
    return 0;
}

float distance_point_to_point(point &p1, point &p2)
{
    float d_x = (p1.x - p2.x) * (p1.x - p2.x);
    float d_y = (p1.y - p2.y) * (p1.y - p2.y);
    float res = sqrt(d_x + d_y);
    return res;
}

float distance_point_to_line(point &p, line &l)
{
    float mau = sqrt(l.a * l.a + l.b * l.b);
    float tu = abs(l.a * p.x + l.b * p.y + l.c);
    float res = tu / mau;
    return res;
}