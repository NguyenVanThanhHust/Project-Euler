//UVa 1363 Rail
#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <string>

using namespace std;

void print_result(queue<int> stationB, int N);

string isPossible(queue<int> station, int N);

int main()
{
	int N;
	cin >> N;
	while (N!=0)
	{
		
		queue<int> stationB;
		int input;
		cin >> input;
		while (input != 0)
		{
			stationB.push(input);
			cin >> input;
		}
		print_result(stationB, N);
		cout << endl;
		cin >> N;
	}
	return 0;
	
}

void print_result(queue<int> stationB, int N)
{
	int number_of_case = (int)stationB.size() / N;
	deque<queue<int>> list_of_case;
	for (size_t i = 0; i < number_of_case; i++)
	{
		queue<int> particular_case;
		for (size_t j = 0; j < N; j++)
		{
			int k = stationB.front();
			particular_case.push(k);
			stationB.pop();
		}
		list_of_case.push_back(particular_case);
	}

	for (size_t i = 0; i < number_of_case; i++)
	{
		string result = isPossible(list_of_case[0], N);
		cout << result << endl;
		list_of_case.pop_front();
	}

}

string isPossible(queue<int> station, int N)
{
	queue<int> init_station;
	for (size_t i = 0; i < N; i++)
	{
		init_station.push(i + 1);
	}
	stack<int> middle;
	while ( !init_station.empty() )
	{
		if ( middle.empty())
		{
			int k = init_station.front();
			middle.push(k);
			init_station.pop();
		}
		else
		{
			if (middle.top() == station.front())
			{
				middle.pop();
				station.pop();
			}
			else
			{
				int k = init_station.front();
				middle.push(k);
				init_station.pop();
			}
		}
	}

	// now, init_station is empty
	int m_size = station.size();
	if (station.size() != middle.size() )
	{
		return "No";
	}
	else
	{
		for (size_t i = 0; i < m_size; i++)
		{
			if (station.front() == middle.top())
			{
				station.pop();
				middle.pop();
			}
			else
			{
				return "No";
			}
		}
		return "Yes";
	}
}