#include <iostream>
#include <algorithm>

#define MAX 1000

int w[MAX] = { 0, };
int d[MAX] = { 1, };

int main()
{
	using namespace std;

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> w[i];

	int res = 0;
	for (int i = 1; i < n; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
		{
			if (w[i] > w[j] && max < d[j])
				max = d[j];
		}

		d[i] = max + 1;

		if (res < d[i])
			res = d[i];
	}

	cout << res << endl;
	getchar();
	getchar();

	return 0;
} 