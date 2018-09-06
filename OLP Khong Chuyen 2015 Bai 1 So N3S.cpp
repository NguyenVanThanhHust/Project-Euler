#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<long long> v;

void generate(unsigned long long k)
{
	for (unsigned long long i = 0; i < k; i += 3)
	{
		unsigned long long h = i + 1;
		unsigned long long g = sqrt(h);
		if (pow(g, 2) - h == 0)
		{
			v.push_back(h - 1);
		}
	}
}

int main()
{
	int t;
	unsigned long k, m;
	cin >> t;
	generate(pow(10, 9));
	for (int i = 0; i < t; i++)
	{
		cin >> k >> m;
		unsigned long long g = v[k - 1];
		unsigned long long res = g%m;
		cout << res << endl;
	}
	return 0;
}