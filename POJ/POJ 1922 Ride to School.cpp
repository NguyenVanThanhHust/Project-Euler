#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	const double DISTANCE = 4.50;
	while (true)
	{
		int n;
		cin >> n;
		double t_min = 0, v = 0, t = 0, min = 1e6;
		if (n == 0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> v >> t;
			if (t >= 0)
			{
				t_min = DISTANCE / v * 3600 + t;
				if (t_min < min)
				{
					min = t_min;
				}
			}

		}
		cout << setprecision(0) << ceil(min) << endl;
	}
	return 0;
}