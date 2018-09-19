#include <math.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>

using namespace std;

struct loc
{
	long int x,y;
}

struct move
{
	string c;
	int idx;
}

int main()
{
	long int a,b,c,d;
	cin>>a>>b>>c>>d;
	loc start, end;
	start.x=a;start.y=b;
	end.x=c;end.y=d;
	string t;cin>>t;
	string g = "ENWS";
	vector<move> right;
	vector<move> wrong;
	
	return 0;
}