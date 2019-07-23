#include <iostream>
#include <cmath>
#include <stdio.h>
#include <math.h>

# define M_PI           3.14159265358979323846
# define eps 1e-5
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	double a, b, c;
	while (scanf("%lf %lf %lf", &a, &b, &c) == 3)
	{
		double half_perimeter = (a + b + c) / 2;
		double area = sqrt(half_perimeter * (half_perimeter - a) * (half_perimeter - b) *(half_perimeter - c));
		if (a == 0 || b == 0 || c == 0)
			area = 0, half_perimeter = 1;
		printf("The radius of the round table is: %.3lf\n", area / half_perimeter);
	}
    return 0;
}
