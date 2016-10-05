#include <iostream>

using namespace std;

int D[31] = { 1, 0, 3 };

int tiling(const int& n)
{
	if (n < 0) return 0;
	if (D[n] > 0) return D[n];

	D[n] = tiling(n - 2) * 3;
	for (int i = 4; i <= n; i += 2)
		D[n] += tiling(n - i) * 2;

	return D[n];
}

int main()
{
	int n = 0;
	int res = 0;
	
	cin >> n;
	if (n % 2 != 0)
		res = 0;
	else
		res = tiling(n);

	cout << res << endl;

	return 0;
}