#include <iostream>
#include <algorithm>

#define MAX 100000

int w[2][MAX + 1] = { 0, };
int d[2][MAX + 1] = { 0, };

int main()
{
	using namespace std;

	int t, n;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0; j < 2; j++)
			for (int k = 1; k < n + 1; k++)
				cin >> w[j][k];

		d[0][1] = w[0][1];
		d[1][1] = w[1][1];

		for (int j = 2; j <= n; j++)
		{
			d[0][j] = max(d[1][j - 1], d[1][j - 2]) + w[0][j];
			d[1][j] = max(d[0][j - 1], d[0][j - 2]) + w[1][j];
		}

		cout << ((d[0][n] > d[1][n]) ? d[0][n] : d[1][n]) << endl;
	}

	getchar();
	getchar();

	return 0;
} 