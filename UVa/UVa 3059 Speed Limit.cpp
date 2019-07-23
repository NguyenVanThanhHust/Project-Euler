#include <iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n, n > 0)
	{
		int s[11], t[11];
		int total_miles = 0;
		s[0] = t[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i] >> t[i];
			total_miles += s[i] * (t[i] - t[i - 1]);
		}
		cout << total_miles << " miles" << endl;
	}
	return 0;
}