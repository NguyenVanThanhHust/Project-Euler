#include <iostream>
#include <string>

using namespace std;

int main()
{
	long int n;
	cin >> n;
	for (long int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		long sum = 0;
		for (int j = 0; j < s.length(); j++)
		{
			int k = s[j] - '0';
			sum += k;
		}
		cout << sum << endl;
	}
	return 0;
}