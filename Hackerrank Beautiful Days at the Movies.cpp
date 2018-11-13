// hackerrank a beautiful day
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// Wrong Solution
//unsigned long long int reverse_num(unsigned long long int n1)
//{
//	string str = to_string(n1);
//	reverse(str.begin(), str.end());
//	unsigned long long int result = stoul(str, nullptr, 0);
//	return result;
//
//}
//unsigned long long int num_good_day(unsigned long long int n1, unsigned long long int n2, unsigned long long k)
//{
//	unsigned long long int res = 0;
//	unsigned long long int distance = n2 - n1 + 1;
//	for (auto i = 0; i != distance; ++i)
//	{
//		long long int diff = ((n1 + i) - reverse_num(n1 + i));
//		unsigned long long int abs_diff = abs(diff);
//		if (abs_diff%k == 0)
//		{
//			res++;
//		}
//
//	}
//	return res;
//}

//right solution
int beautifulDays(int i, int j, int k) {
	int num, count = 0, gn;
	int quo, newNum = 0, x = 0;
	for (int x = i; x <= j; x++)
	{
		num = x;
		newNum = 0;
		//For reversing no
		while (num != 0)
		{
			quo = num % 10;
			newNum = 10 * newNum + quo;
			num = num / 10;
		}
		gn = abs(x - newNum);
		if (gn%k == 0)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	unsigned long long int n1, n2;
	unsigned long long k;
	cin >> n1 >> n2 >> k;
	cout << beautifulDays(n1, n2, k);
	cout << endl;
	return 0;

}