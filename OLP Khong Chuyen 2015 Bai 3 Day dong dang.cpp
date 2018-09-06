#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

struct pos
{
	vector<int> index;
	unsigned long long v;
};

struct compare
{
	inline bool operator() (const pos &p1, const pos &p2)
	{
		return (p1.v < p2.v);
	}
};

int main()
{
	int t;
	cin >> t;

	
	vector<pos> seq;
	vector<unsigned long long> res;
	unsigned long long value;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			pos a;
			cin >> value;
			a.v = value;
			a.index.push_back(j);
			seq.push_back(a);
			res.push_back(value);
		}
		sort(seq.begin(), seq.end(), compare());

		for (int i = 0; i < seq.size() - 1; i++)
		{
			if (seq[i].v == seq[i + 1].v)
			{
				int k = seq[i + 1].index[0];
				seq[i].index.push_back(k);
				seq.erase(seq.begin() + i);
			}
		}

		for (unsigned long long int i = 0; i < seq.size(); i++)
		{
			vector<int> k = seq[i].index;
			for (int j = 0; j < k.size(); j++)
			{
				int g = k[j];
				res[g] = i + 1;
			}
		}

		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << " ";
		}
		cout << endl;
	}

	return 0;
}