#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		string s;
		cin >> s;
		int diem = 0, tong_diem = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'C')
			{
				diem++;
				tong_diem += diem;
			}
			else
			{
				diem = 0;
			}
		}
		cout << tong_diem << endl;
		n--;
	}
	return 0;
}