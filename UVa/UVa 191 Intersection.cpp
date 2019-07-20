//UVA 191 Intersection
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t != 0)
	{
		int xs, ys, xe, ye;
		cin >> xs >> ys >> xe >> ye;
		int xl, yt, xr, yb;
		cin >> xl >> yt >> xr >> yb;
		float a, b, c;
		b = -xs + xe;
		a = ys - ye;
		c = -xe*ys + xs*ye;
		float v[4];
		v[0] = a*xl + b*yt + c;
		v[1] = a*xl + b*yb + c;
		v[2] = a*xr + b*yt + c;
		v[3] = a*xr + b*yb + c;
		string tf = "F";
		if (v[0] == 0)
		{
			tf = "T";
		}
		if (v[0] < 0)
		{
			for (int i = 1; i < 4; i++)
			{
				if (v[i] >= 0)
				{
					tf = "T";
				}
			}
		}
		if(v[0]>0)
		{
			for (int i = 1; i < 4; i++)
			{
				if (v[i] <= 0)
				{
					tf = "T";
				}
			}
		}
		
		cout << tf << endl;
		t--;
 	}
	return 0;
}