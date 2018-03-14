#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
vector<int> g_arr;
long long high = -pow(2, 62);
long long low = pow(2, 62);

void DFS(int plus, int minus, int div, int mul, long long total = 0, int idx = 1)
{
	if (idx >= g_arr.size())
	{
		high = (total > high) ? total : high;
		low = (total < low) ? total : low;
		return;
	}

	if (plus > 0)
		DFS(plus - 1, minus, div, mul, total + g_arr[idx], idx + 1);
	if (minus > 0)
		DFS(plus, minus - 1, div, mul, total - g_arr[idx], idx + 1);
	if (div > 0)
		DFS(plus, minus, div - 1, mul, total / g_arr[idx], idx + 1);
	if (mul > 0)
		DFS(plus, minus, div, mul - 1, total * g_arr[idx], idx + 1);	
}

int main()
{
	int N;
	cin >> N;
	g_arr.resize(N);

	for (int i = 0; i < N; i++)
		cin >> g_arr[i];

	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;
	DFS(plus, minus, div, mul, g_arr[0]);

	cout << high << endl;
	cout << low << endl;

	return 0;
}

