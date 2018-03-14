#include <iostream>
#include <vector>

using namespace std;

vector<int> g_rooms;

int main()
{
	int N;
	cin >> N;
	g_rooms.resize(N);

	for (int i = 0; i < N; i++)
		cin >> g_rooms[i];

	int B, C;
	cin >> B >> C;

	long long total = 0;
	for (int i = 0; i < g_rooms.size(); i++)
	{
		int b = (int)(g_rooms[i] != 0);
		g_rooms[i] -= b * B;
		g_rooms[i] = (g_rooms[i] < 0) ? 0 : g_rooms[i];

		int c = (g_rooms[i] % C != 0) ? g_rooms[i] / C + 1 : g_rooms[i] / C;

		total += b + c;
	}

	cout << total << endl;

	return 0;
}

