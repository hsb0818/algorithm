#include <iostream>

using namespace std;

int D[1001] = { 1, 1, };

int tiling(const int& n)
{
	if (D[n] > 0)
		return D[n];

	D[n] = (tiling(n - 2) + tiling(n - 1)) % 10007;	
	
	return D[n];
}

int main()
{	
	int n = 0;

	cin >> n;

	if ((n > 1000) || (n < 1))
		return 0;
	
	cout<< tiling(n) <<endl;
	
	return 0;
}