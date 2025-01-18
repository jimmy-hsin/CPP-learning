#include <bits/stdc++.h>

using namespace std;

int main()
{
	int W, T, w[10], t[10], p[10];
	int n;

	cin >> n >> W >> T;

	for (int i = n - 1; i >= 0; i--)
	{
		cin >> w[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		cin >> t[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		cin >> p[i];
	}


	int tempRev, tempW, tempT, tempAmount, maxRev = -1;

	for (int i = 0; i * w[n - 1] <= W && i * t[n - 1] <= T; i++)
	{
		tempW = W - i * w[n - 1];
		tempT = T - i * t[n - 1];
		tempRev = i * p[n - 1];
		for (int j = n - 2; j >= 0; j--)
		{
			if (tempW / w[j] && tempT / t[j])
			{
				tempAmount = min(tempW / w[j], tempT / t[j]);

				tempRev += tempAmount * p[j];
				tempW -= tempAmount * w[j];
				tempT -= tempAmount * t[j];
			}
		}

		maxRev = max(maxRev, tempRev);
	}

	cout << maxRev << '\n';

	return 0;
}
