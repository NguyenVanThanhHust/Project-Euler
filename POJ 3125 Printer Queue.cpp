// POJ 3125
#include <iostream>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		int *print_queue = new int[2 * n];
		// take input
		for (size_t i = 0; i < n; i++)
		{
			cin >> print_queue[i];
			print_queue[i + n] = print_queue[i];
		}

		int time_to_process = 0;
		int biggest_pos = -1;
		int biggest = print_queue[m];
		for (size_t i = 0; i < n; i++)
		{
			if (print_queue[i] > biggest)
			{
				biggest = print_queue[i];
				biggest_pos = i;
			}
		}

		if (biggest_pos == -1)
		{
			for (size_t i = 0; i <= m; i++)
			{
				if (print_queue[i] == print_queue[m])
				{
					time_to_process++;
				}
			}
			cout << time_to_process << endl;
		}
		else
		{
			for (size_t i = biggest_pos; i <= m + n; i++)
			{
				if (print_queue[i] >= print_queue[m])
				{
					time_to_process++;
				}
			}
			cout << time_to_process << endl;
		}
	}
	return 0;
}