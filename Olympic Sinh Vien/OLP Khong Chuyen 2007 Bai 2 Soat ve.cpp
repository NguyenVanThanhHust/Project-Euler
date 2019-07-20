#include <math.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> len;
	vector<int> xuong;
	len.push_back(0);
	xuong.push_back(0);

	int a = 0, b = 0, c, d;
	for (int i = 1; i <= n; i++)
	{
		cin >> c >> d;
		a += c;
		b += d;
		if ((i - 1) % k == 0)
		{
			len.push_back(a);
			xuong.push_back(b);
			a = 0; b = 0;
		}
	}

	vector<int> khach_tren_xe;
	khach_tren_xe.push_back(0);
	for (int i = 1; i < len.size(); i++)
	{
		int k = len[i] - xuong[i] + khach_tren_xe[i - 1];
		khach_tren_xe.push_back(k);
	}

	int max_loss = 0, min_loss = 0;
	for (int i = 2; i < khach_tren_xe.size(); i++)
	{
		if (len[i] >= xuong[i])
		{
			max_loss += xuong[i];
		}
		else
		{
			max_loss += len[i];
		}
	}
	for (int i = 2; i < khach_tren_xe.size(); i++)
	{
		if (xuong[i] <= khach_tren_xe[i - 1])
		{
			min_loss = min_loss;
		}
		else
		{
			min_loss += xuong[i] - khach_tren_xe[i - 1];
		}
	}

	cout << min_loss << " " << max_loss << endl;
	return 0;
}