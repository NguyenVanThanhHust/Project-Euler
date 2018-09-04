#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	unsigned long long m;
	unsigned int k;
	int day = 0;
	cin >> m >> k;
	unsigned long long a = 0, b = 0;
	for (unsigned int i = 0; i < k; i++)
	{
		cin >> a;
		b += a;
		if (b > m)
		{
			b = b%m;
			day++;
		}
	}
	cout << day << endl;
	return 0;
}