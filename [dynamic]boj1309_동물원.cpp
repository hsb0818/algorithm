#include <iostream>

#define MAX 100000

int d[MAX][3] = { 0, };

int main()
{
	using namespace std;
	
	d[0][0] = d[0][1] = d[0][2] = 1;

	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		d[i][0] = (d[i - 1][1] + d[i - 1][2]) % 9901;
		d[i][1] = (d[i - 1][0] + d[i - 1][2]) % 9901;
		d[i][2] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % 9901;
	}

	cout << (d[n - 1][0] + d[n - 1][1] + d[n - 1][2]) % 9901 << endl;

	return 0;
} 