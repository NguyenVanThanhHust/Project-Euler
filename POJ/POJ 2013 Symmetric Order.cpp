
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int k = 1;
	while (n != 0)
	{
		queue<string> q;
		stack<string> s;
		for (int i = 1; i <= n; i++)
		{
			string temp;
			cin >> temp;
			if (i % 2 == 1)
			{
				q.push(temp);
			}
			else
			{
				s.push(temp);
			}
		}
		cout << "SET " << k << endl;
		while (!q.empty())
		{
			string temp;
			temp = q.front();
			cout << temp << endl;
			q.pop();
		}
		while (!s.empty())
		{
			string temp;
			temp = s.top();
			cout << temp << endl;
			s.pop();
		}
		k++;
		cin >> n;
	}
	return 0;
}