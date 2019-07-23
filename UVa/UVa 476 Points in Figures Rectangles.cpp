#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct rectange
{
	float xl, xr, yt, yb;
};

struct point
{
	float x, y;
	int index;
	vector<int> vir; // vector index of rectangle
};

// algorithm
bool inRect(rectange &r, point &p)
{
	if (r.xl <= p.x && p.x <= r.xr && r.yb <= p.y && p.y <r.yt)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string str;
	cin >> str;
	vector<rectange> vr;
	while (str == "r")
	{
		float xl, yt, xr, yb;
		cin >> xl >> yt >> xr >> yb;
		rectange r;
		r.xl = xl;
		r.yt = yt;
		r.xr = xr;
		r.yb = yb;
		vr.push_back(r);
		cin >> str;
	}

	std::vector<point> vp;
	double x, y;
	int index = 0;
	for (index = 0; cin >> x >> y && x != 9999.9 && y!= 9999.9;)
	{
		point p;
		p.x = x;
		p.y = y;
		p.index = index + 1;
		vp.push_back(p);
		index++;
	}

	for (int i = 0; i<vp.size(); i++)
	{
		for (int j = 0; j < vr.size(); j++)
		{
			/* code */
			if (inRect(vr[j], vp[i]) == true)
			{
				vp[i].vir.push_back(j + 1);
			}
		}
	}

	for (int i = 0; i < vp.size(); ++i)
	{
		/* code */
		if (!vp[i].vir.empty())
		{
			for (int j = 0; j<vp[i].vir.size(); j++)
			{
				cout << "Point " << vp[i].index << " is contained in figure " << vp[i].vir[j] << endl;
			}
		}
		else
		{
			cout << "Point " << vp[i].index << " is not contained in any figure" << endl;
		}
	}
	return 0;
}
// Test case
r 8.5 17.0 25.5 -8.5
r 0.0 10.3 5.5 0.0
r 2.5 12.5 12.5 2.5
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9