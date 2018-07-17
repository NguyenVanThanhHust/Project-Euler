#include <iostream>
#include <math.h>

using namespace std;

#define PI 3.14159265359
double distance(double x1, double y1, double x2, double y2)
{
	double k1 = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	double k2 = sqrt(k1);
	return k2;
}
int main()
{
	double x1, y1, x2, y2, x3, y3;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{
		
		double a, b, c;
		a = distance(x1, y1, x2, y2);
		
		b = distance(x2, y2, x3, y3);
		c = distance(x3, y3, x1, y1);
		
		double p = (a + b + c) / 2;
		double s = sqrt(p*(p - a)*(p - b)*(p - c));
		double d = a*b*c / (2 * s);
		
		double C = PI*d;
		cout.precision(2);
		cout << fixed << C << endl;

	}
	return 0;
}