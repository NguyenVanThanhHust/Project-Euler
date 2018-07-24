#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;
#define N 10000

unsigned int g[N];
int sum_of_digits(int n)
{
	if (n < 10)
		return n;
	else
		return n % 10 + sum_of_digits(n / 10);
}

void generate_sequence(unsigned int n)
{
	while (n < N)
	{
		unsigned int next = n + sum_of_digits(n);
		if (n > N || g[next] != next)
			return;
		else
		{
			g[next] = next;
			n = next;
		}
	}
}


int main()
{
	for (int n = 1; n < N; n++)
	{
		g[n] = n;
	}
	for (int n = 1; n < N; n++)
	{
		generate_sequence(n);
	}
	for (int n = 1; n < N; n++)
	{
		if (g[n] == n)
			cout << g[n] << endl;
	}
	return 0;
}