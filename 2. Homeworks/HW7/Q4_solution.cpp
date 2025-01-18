#include <bits/stdc++.h>

using namespace std;


int main ()
{
	int primes[100000], smallestPrimeDivisorIndex[1000001] = {0}, numPrimes = 0;

/*
	primes =                    {2, 3, 5, 7, 11, ...}

	smallestPrimeDividerIndex = {0, 0, 1, 0, 2, 0, 3, 0, 1, 0, 4, ...}

*/

	int n, num;
	int pow;

	cin >> n;

	bool first;

	for (int i = 2; i <= n; i++)
	{
		num = i;
		first = true;

		for (int j = 0; j < numPrimes && static_cast<double>(primes[j]) <= sqrt(num);)
		{
			pow = 0;
			
			while (!(num % primes[j]))
			{
				num /= primes[j];
				++pow;
			}
			
			if (pow == 1)
			{
				if (!first) cout << " * ";
				else 
				{
					first = false;
					smallestPrimeDivisorIndex[i] = j;
				}

				cout << primes[j];
			}
			else if (pow > 1)
			{
				if (!first) cout << " * ";
				else 
				{
					first = false;
					smallestPrimeDivisorIndex[i] = j;
				}
				
				cout << primes[j] << " ^ " << pow;
			}

			if (num == 1) break;

			if (smallestPrimeDivisorIndex[num])
			{
				j = smallestPrimeDivisorIndex[num];
			}
			else
			{
				++j;
			}
		}

		if (first)
		{
			cout << num;
			primes[numPrimes] = num;
			smallestPrimeDivisorIndex[i] = numPrimes;
			++numPrimes;
		}
		else if (num > 1)
		{
			cout << " * " << num;
		}

		cout << '\n';
	}

	
	return 0;
}