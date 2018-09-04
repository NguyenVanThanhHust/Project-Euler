#include <iostream>
#include <vector>
#include <limits>
#include <limits.h>

using namespace std;

int main()
{
	vector<long long> ln;
	unsigned long int n;
	cin >> n;
	long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;
	long long k;
	for (unsigned long int i = 0; i < n; i++)
	{
		cin >> k;
		if (k >= max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = k;
		}
		else if (k >= max2 && k < max1)
		{
			max3 = max2;
			max2 = k;
		}
		else if (k > max3 && k < max2)
		{
			max3 = k;
		}
	}
	long long res;
	res = max1 * 3 + max2 * 2 + max3;
	cout << res << endl;
	return 0;
}