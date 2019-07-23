#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdio.h>
using namespace std;

long int find_large(long int k)
{
	string s = to_string(k);
	int usable[10];
	for (int i = 0; i < 10; i++)
	{
		usable[i] = 1;
	}
	vector<int> digit;
	for (int i = 0; i < s.length(); i++)
	{
		int g = s[i] - '0';
		digit.push_back(g);
		usable[g] = 0;
	}

	long int result;
	int first_digit = 0;
	for (int i = 1; i < 10; i++)
	{
		if (usable[i] != 0 && i > digit[0])
		{
			first_digit = i;
			break;
		}
	}
	if (first_digit == 0)
	{
		for (int i = 1; i < 10; i++)
		{
			if (usable[i] != 0)
			{
				first_digit = i;
				result = first_digit;
				break;
			}
		}

		for (int i = 0; i < s.length(); i++)
		{
			int index = 0;
			while (usable[index] == 0)
			{
				index++;
				
			}
			result = result * 10 + index;
		}
	}
	else
	{
		result = first_digit;
		for (int i = 1; i < s.length(); i++)
		{
			int index = 0;
			while (usable[index] == 0)
			{
				index++;
				
			}
			result = result * 10 + index;
		}
	}
	return result;
}

int main()
{
	vector<long int> a;

	for (int i = 0; i <= 10; i++)
	{
		a.push_back(i);
	}
	a.push_back(22);

	for (int i = 11; i < 500; i++)
	{
		long int k = find_large(a[i]);
		a.push_back(k);
	}
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		int n;
		cin >> n;
		cout << a[n] << endl;
	}
	return 0;
}