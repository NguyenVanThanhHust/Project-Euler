#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n > -1)
	{
		long long int a = 1;
		long long int b = 0;
		for (int i = 0; i < n; i++)
		{
			long long int c, d;
			c = 1 + b;
			d = a + b;
			a = c;
			b = d;
		}
		cout << b << " " << a + b << endl;
		cin >> n;
	}
	return 0;
}