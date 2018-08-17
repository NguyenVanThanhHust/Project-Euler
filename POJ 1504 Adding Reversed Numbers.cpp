#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		string a, b;
		vector<int> va, vb;
		cin >> a >> b;
		for (int i = 0; i < a.length(); i++)
		{
			int k = a[i] - '0';
			va.push_back(k);
		}
		for (int i = 0; i < b.length(); i++)
		{
			int k = b[i] - '0';
			vb.push_back(k);
		}
		if (a.length() > b.length())
		{
			va.push_back(0);
			for (int i = 0; i <= a.length() - b.length(); i++)
			{
				vb.push_back(0);
			}
		}
		else
		{
			vb.push_back(0);
			for (int i = 0; i <= b.length() - a.length(); i++)
			{
				va.push_back(0);
			}
		}

		vector<int> vc = va;
		for (int i = 0; i < va.size(); i++)
		{
			vc.at(i) = va.at(i) + vb.at(i);
		}
		for (int i = 0; i < vc.size() - 1; i++)
		{
			if (vc.at(i) >= 10)
			{
				vc.at(i) = vc.at(i) - 10;
				vc.at(i + 1)++;
			}
		}
		while (vc.back() == 0)
		{
			vc.pop_back();
		}
		stack<int> s;
		while (vc.size() != 0)
		{
			int k = vc.back();
			s.push(k);
			vc.pop_back();
		}
		while (s.top() == 0)
		{
			s.pop();
		}
		while (!s.empty())
		{
			int k = s.top();
			cout << k;
			s.pop();
		}
		cout << endl;
		n--;
	}
	return 0;
}
