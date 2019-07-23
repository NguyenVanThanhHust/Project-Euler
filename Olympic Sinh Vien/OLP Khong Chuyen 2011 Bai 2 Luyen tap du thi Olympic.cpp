#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct bai
{
	unsigned long a;
	unsigned long b;
};

struct compare
{
	inline bool operator()(const bai &bai1, const bai &bai2)
	{
		return (bai1.a < bai2.a);
	};
};
int main()
{
	unsigned long n, c;
	cin >> n >> c;
	vector<bai> prob;
	unsigned long sol = 0;
	for (unsigned long i = 0; i < n; i++)
	{
		bai tem_b;
		unsigned long a, b;
		cin >> a >> b;
		tem_b.a = a;
		tem_b.b = b;
		prob.push_back(tem_b);
	}
	
	sort(prob.begin(), prob.end(), compare());
	for (unsigned long i = 0; i < n; i++)
	{
		if (c >= prob[i].a)
		{
			c += prob[i].b;
			sol++;
		}
		else
		{
			break;
		}
	}
	cout << sol << endl;
	return 0;
}