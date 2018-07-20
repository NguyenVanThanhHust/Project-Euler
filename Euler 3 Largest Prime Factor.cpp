#include "Library.h"
// Main idea : divide n to 2 and odd number
// Because the odd number contain all prime factor except 2, so we can put it into loop

int maxPrimeFactor(long long int n)
{
	int maxPF = 0;
	if (n % 2 == 0)
	{
		maxPF = 2;
		n >>= 1;// == n/2
	}

	// from now n is an odd number
	for (int i = 3; i, sqrt(n); i = i + 2)
	{
		while (n%i == 0)
		{
			maxPF = i;
			n = n / i;
		}
	}
	return maxPF;
}

int main()
{
	long long int n = 600851475143;
	int res = maxPrimeFactor(n);
	cout << res << endl;
	return 0;

}