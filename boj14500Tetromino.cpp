#include <iostream>

using namespace std;

const int MAX_SIZE = 500;
int N, M;

int map[MAX_SIZE + 1][MAX_SIZE + 1] = { 0, };
bool visit[MAX_SIZE + 1][MAX_SIZE + 1] = { 0, };

int g_max = 0;
void find_max_value(int x, int y, int val = 0, int step = 1)
{
	if (x < 0 || y < 0 ||
		x >= M || y >= N)
		return;
	if (visit[y][x])
		return;
	
	val += map[y][x];

	if (step == 4)
	{
		if (val > g_max)
			g_max = val;

		return;
	}

	visit[y][x] = true;
	find_max_value(x + 1, y, val, step + 1);
	find_max_value(x - 1, y, val, step + 1);
	find_max_value(x, y + 1, val, step + 1);
	find_max_value(x, y - 1, val, step + 1);
	visit[y][x] = false;
}

int calc_special(int x, int y)
{
	int d[4][2] = {
		{-1, 0},
		{+1, 0},
		{0, -1},
		{0, +1}
	};

	int err = 0;
	int sum = map[y][x];
	int min = 999999;
	for (int i = 0; i < 4; i++)
	{
		int cx = x + d[i][0];
		int cy = y + d[i][1];

		if (cx >= M || cx < 0 ||
			cy >= N || cy < 0)
		{
			err++;
			if (err >= 2)
				return 0;

			continue;
		}

		sum += map[cy][cx];

		if (err > 0)
			continue;
		else if (map[cy][cx] < min)
			min = map[cy][cx];
	}

	if (err == 0)
		sum -= min;

	return sum;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			find_max_value(j, i);
		
			int special = calc_special(j, i);
			if (special > 0 && special > g_max)
				g_max = special;
		}
	}

	cout << g_max << endl;

	return 0;
}