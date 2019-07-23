#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define N 500

int main()
{
	int a, b;
	vector<int> attend;
	
	while (cin >> a >> b, (a || b))
	{
		// a : number of alumin
		// b : number of dinner
		attend.assign(a + 1, 1);
		int k;
		for (int i = 1; i <= b; i++)
		{
			for (int j = 1; j <= a; j++)
			{
				cin >> k;
				if (k == 0)
				{
					attend[j] = 0;
				}
			}
		}

		int alumin = 0;
		for (int i = 1; i <= a; i++)
		{
			if (attend[i] == 1)
			{
				alumin = 1;
			}
		}


		if (alumin == 1)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
		
	}
	return 0;


}