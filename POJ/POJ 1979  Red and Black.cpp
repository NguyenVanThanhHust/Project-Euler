#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

const int maxn = 20 + 5, maxm = 20 + 5; // maximum number of row and column
int n, m, ans; // number of row and column and possilbe black position that man can reach
string map[maxn];
bool visited[maxn][maxm];
void search(int row, int col)
{
	// recursively count the number of black tiles which man can reach from position[row, col]
	if (row < 0 || row >= n || // outside of map
		col < 0 || col >= m ||
		map[row][col] == '#' || // unvisitable
		visited[row][col]) // visited
	{
		return;
	}

	visited[row][col] = true;
	++ans;
	search(row - 1, col);
	search(row + 1, col);
	search(row, col - 1);
	search(row, col + 1);
}

int main()
{
	cin >> m >> n;
	while (n || m)
	{
		int row, col;
		for (int i = 0; i < n; i++)
		{
			cin >> map[i];
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == '@')
				{
					row = i;
					col = j;
				}
			}
			memset(visited, false, sizeof(visited));
			ans = 0;
			search(row, col);
			cout << ans << endl;

			cin >> m >> n;

		}
	}
	return 0;
}