// Khoi sieu cup 2005 bai 1 VIPLIST
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// idea : sap xep theo so luong nguoi quen biet
// neu so luong nguoi quen biet >= k, , dung
// neu ko, xoa het nhung nguoi co so luong nguoi quen < k
// nhung nguoi con lai
struct member
{
	int index;
	int num_rel;
	vector<int> relatives;
};


struct compare_num_relative
{
	inline bool operator()(const member &m1, const member &m2)
	{
		return m1.num_rel > m2.num_rel;

	};
};

void m_erase(vector<int> &relatives, int index)
{
	for (size_t i = 0; i < relatives.size() ; i++)
	{
		if (relatives[i] == index)
		{
			relatives.erase(relatives.begin() + i);
			break;
		}
	}
}

int main()
{
	int n, k;
	vector<member> members;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		member m;
		int number;
		vector<int> relative;
		m.index = i;
		cin >> number;
		for (size_t j = 0; j < number; j++)
		{
			int temp;
			cin >> temp;
			relative.push_back(temp - 1);
		}
		m.relatives = relative;
		m.num_rel = number;
		members.push_back(m);
	}

	// check to find if all member's relative is listed and counted 
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < members[i].num_rel; j++)
		{
			int k = members[i].relatives[j];
			members[k].num_rel++;
			members[k].relatives.push_back(i);
		}
	}
	
	for (size_t i = 0; i < n; i++)
	{
		vector<int> vec = members[i].relatives;
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		members[i].relatives = vec;	
		members[i].num_rel = members[i].relatives.size();
	}

	/*for (size_t i = 0; i < n; i++)
	{
		vector<int> temp_relatives;
		sort(members[i].relatives.begin(), members[i].relatives.end());
		members[i].relatives.push_back(members[i].relatives[members[i].relatives.size() - 1]);
		for (size_t j = 0; j < members[i].relatives.size() - 1; j++)
		{
			if (members[i].relatives[j] == members[i].relatives[j + 1])
			{
				members[i].relatives.erase(members[i].relatives.begin() + j);
			}
		}
		members[i].num_rel = members[i].relatives.size();
	}
*/

	bool erase = true;
	sort(members.begin(), members.end(), compare_num_relative());
	int result;
	if (k > members[members.size() - 1].num_rel)
	{
		erase = true;
	}
	else
	{
		erase = false;
		result = members.size();
	}

	while (erase)
	{
		int index_to_erase = 0;
		for (size_t i = 0; i < members.size(); i++)
		{
			if (k > members[i].num_rel)
			{
				index_to_erase = i;
				break;
			}
		}


		for (size_t i = members.size() - 1; i > index_to_erase; i--)
		{
			int index = members[i].index;
			for (size_t j = 0; j < index_to_erase; j++)
			{
				m_erase(members[j].relatives, index);
				members[j].num_rel--;
			}
		}
		while (members.size() > index_to_erase)
		{
			members.pop_back();
		}
		if (members.size() == 0)
		{
			result = -1;
			erase = false;
		}
		sort(members.begin(), members.end(), compare_num_relative());

		if (k > members[members.size() - 1].num_rel )
		{
			erase = true;
		}
		else
		{
			erase = false;
			result = members.size() - 1;
		}
	

	}
	cout << result << endl;
	return 0;
}