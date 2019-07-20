/// UVa 361 Cops and Robbers
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(int i = a; i <=b ; ++i)
struct cops
{
	int x, y;
};


struct robber
{
	int x, y;
};

struct citizen
{
	int x, y;
	bool is_safe = false;
	bool is_robbed = false;
	bool neither = false;
};

struct group_of_cop
{
	cops c1;
	cops c2;
	cops c3;
};

struct group_of_robber
{
	robber r1;
	robber r2;
	robber r3;
};

bool is_safe(citizen &o, group_of_cop &g);
bool is_robbed(citizen &o, group_of_robber &g);

int main()
{
	int c, r, o;// cop robber, other citizen
	cin >> c >> r >> o;
	int step = 1;
	while (c!=0 || r!= 0 || o!=0)
	{
		vector<cops> v_cops;
		int x, y;
		FOR(i, 0, c - 1)
		{
			cin >> x >> y;
			cops c;
			c.x = x;
			c.y = y;
			v_cops.push_back(c);
		}

		vector<robber> v_robber;
		FOR(i, 0, r - 1)
		{
			cin >> x >> y;
			robber r;
			r.x = x;r.y = y;
			v_robber.push_back(r);
		}

		vector<citizen> v_citizen;
		FOR(i, 0, o - 1)
		{
			cin >> x >> y;
			citizen c;
			c.x = x;c.y = y;
			v_citizen.push_back(c);
		}

		vector<group_of_cop> v_group_of_cops;
		FOR(i, 0, c - 3)
		{
			FOR(j, i + 1, c - 2)
			{
				FOR(k, j + 1, c - 1)
				{
					group_of_cop tem_g;
					tem_g.c1 = v_cops[i];
					tem_g.c2 = v_cops[j];
					tem_g.c3 = v_cops[k];
					v_group_of_cops.push_back(tem_g);
				}
			}
		}

		vector<group_of_robber> v_group_of_robber;
		FOR(i, 0, r - 3)
		{
			FOR(j, i + 1, r - 2)
			{
				FOR(k, j + 1, r - 1)
				{
					group_of_robber tem_g;
					tem_g.r1 = v_robber[i];
					tem_g.r2 = v_robber[j];
					tem_g.r3 = v_robber[k];
					v_group_of_robber.push_back(tem_g);
				}
			}
		}

		FOR(i, 0, o - 1)
		{
			FOR(j,0, v_group_of_cops.size()-1)
			{
				if(is_safe(v_citizen[i], v_group_of_cops.at(j)))
				{
					v_citizen[i].is_safe = true;
					break;
				}
			}
			FOR(j,0,v_group_of_robber.size()-1)
			{
				if(v_citizen[i].is_safe == false)
				{
					if(is_robbed(v_citizen[i], v_group_of_robber[j]))
					{
						v_citizen[i].is_robbed = true;
						break;
					}
				}
			}
			
			if(v_citizen[i].is_safe == false && v_citizen[i].is_robbed == false)
			{
				v_citizen[i].neither = true;
			}
			
		}
		
		cout<<"Data set "<< step<<" :"<<endl;
		FOR(i,0,o-1)
		{
			if(v_citizen[i].is_safe)
			{
				cout<<"     Citizen at  ("<<v_citizen[i].x<<","<<v_citizen[i].y<<") is safe.\n";
			}
			else if (v_citizen[i].is_robbed)
			{
				cout<<"     Citizen at  ("<<v_citizen[i].x<<","<<v_citizen[i].y<<") is robbed.\n";
			}
			else
			{
				cout<<"     Citizen at  ("<<v_citizen[i].x<<","<<v_citizen[i].y<<") is neither.\n";
			}	
		}
		cout<<endl;
		step++;
		cin>>c>>r>>o;
	}
	return 0;
}

bool is_safe(citizen &o, group_of_cop &g)
{
	int x1 = g.c1.x, y1 = g.c1.y;
	int x2 = g.c2.x, y2 = g.c2.y;
	int x3 = g.c3.x, y3 = g.c3.y;

	int a1 = y2 - y1;
	int b1 = x1 - x2;
	int c1 = x2*y1 - x1*y2;

	int a2 = y3 - y2;
	int b2 = x2 - x3;
	int c2 = x3*y2 - x2*y3;

	int a3 = y1 - y3;
	int b3 = x3 - x1;
	int c3 = x1*y3 - x3*y1;

	int x = o.x, y = o.y;

	int same_side_1 = (a1*x + b1*y + c1)*(a1*x3 + b1*y3 + c1);
	int same_side_2 = (a2*x + b2*y + c2)*(a2*x1 + b2*y1 + c2);
	int same_side_3 = (a3*x + b3*y + c3)*(a3*x2 + b3*b2 + c3);

	if (same_side_1 < 0 || same_side_2 < 0 || same_side_3 < 0)
	{
		return false;
	}
	return true;

}
bool is_robbed(citizen &o, group_of_robber &g)
{
	int x1 = g.r1.x, y1 = g.r1.y;
	int x2 = g.r2.x, y2 = g.r2.y;
	int x3 = g.r3.x, y3 = g.r3.y;

	int a1 = y2 - y1;
	int b1 = x1 - x2;
	int c1 = x2*y1 - x1*y2;

	int a2 = y3 - y2;
	int b2 = x2 - x3;
	int c2 = x3*y2 - x2*y3;

	int a3 = y1 - y3;
	int b3 = x3 - x1;
	int c3 = x1*y3 - x3*y1;

	int x = o.x, y = o.y;

	int same_side_1 = (a1*x + b1*y + c1)*(a1*x3 + b1*y3 + c1);
	int same_side_2 = (a2*x + b2*y + c2)*(a2*x1 + b2*y1 + c2);
	int same_side_3 = (a3*x + b3*y + c3)*(a3*x2 + b3*b2 + c3);

	if (same_side_1 < 0 || same_side_2 < 0 || same_side_3 < 0)
	{
		return false;
	}
	return true;

}