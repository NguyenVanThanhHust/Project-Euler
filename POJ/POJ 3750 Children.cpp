#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> circle;
	for (int i = 0; i < n; i++)
	{
		string t;
		cin >> t;
		circle.push_back(t);
	}

	int w, s;
	scanf("%d,%d", &w, &s);
	w = w - 1;
	while (!circle.empty())
	{
		int k = w + s - 1;
		while (k > circle.size()-1)
		{
			k = k - circle.size();
		}
		string t = circle[k];
		cout << t << endl;
		if (k == circle.size() - 1)
		{
			w = 0;
		}
		else
		{
			w = k;
		}
		circle.erase(circle.begin() + k);
	}
	return 0;
}
