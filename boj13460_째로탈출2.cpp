#include <iostream>

using namespace std;

const int MAX = 11;

const char NONE = '.';
const char BLOCK = '#';
const char GOAL = 'O';
const char R = 'R';
const char B = 'B';

int g_goal = 100;

struct StateMap
{
	int N = 0, M = 0;
	char map[MAX][MAX] = { 0, };

	StateMap(const int _N, const int _M)
		: N(_N)
		, M(_M)
	{
	}

	void print()
	{
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
			{
				printf("%2c", map[r][c]);
			}

			cout << endl;
		}

		cout << endl;
	}

	bool IsLast(const int v, const bool row)
	{
		if (row) return (v != -1) && (v != N);
		else return (v != -1) && (v != M);
	}

	// + : right, down
	// - : left, up
	int Control(const int h, const int v)
	{
		bool b_goal = false;
		bool r_goal = false;
		if (h == 0)
		{
			int last = (v < 0) ? 1 : N - 2;
			for (int c = 0; c < M; c++)
			{
				for (int r = last - v; IsLast(r, true); r -= v)
				{
					if (map[r][c] != R && map[r][c] != B)
						continue;

					int i = r;
					while (true)
					{
						i += v;
						if (map[r][c] == R && map[i][c] == GOAL)
						{
							map[r][c] = NONE;
							r_goal = true;
							break;
						}
						else if (map[r][c] == B && map[i][c] == GOAL)
						{
							map[r][c] = NONE;
							b_goal = true;
							break;
						}
						else if (map[i][c] != NONE)
						{
							map[i - v][c] = map[r][c];
							if (i - v != r)
								map[r][c] = NONE;

							break;
						}
					}
				}
			}
		}
		else if (v == 0)
		{
			int last = (h < 0) ? 1 : M - 2;
			for (int r = 0; r < N; r++)
			{
				for (int c = last - h; IsLast(c, false); c -= h)
				{
					if (map[r][c] != R && map[r][c] != B)
						continue;

					int i = c;
					while (true)
					{
						i += h;
						if (map[r][c] == R && map[r][i] == GOAL)
						{
							map[r][c] = NONE;
							r_goal = true;
							break;
						}
						else if (map[r][c] == B && map[r][i] == GOAL)
						{
							map[r][c] = NONE;
							b_goal = true;
							break;
						}
						else if (map[r][i] != NONE)
						{
							map[r][i - h] = map[r][c];
							if (i - h != c)
								map[r][c] = NONE;

							break;
						}
					}
				}
			}
		}

		if (b_goal)
			return -1;
		if (r_goal && !b_goal)
			return 1;

		return 0;
	}
};

void DFS(StateMap state_map, const int h = 0, const int v = 0, const int step = 0)
{
	if (h != 0 || v != 0)
	{
		int ret = state_map.Control(h, v);
		if (ret == 1)
		{
			if (step < g_goal)
			{
				g_goal = step;
			}
		}
		else if (ret == -1)
			return;
	}

	if (step >= 10)
		return;

	DFS(state_map, -1, 0, step + 1);
	DFS(state_map, +1, 0, step + 1);
	DFS(state_map, 0, -1, step + 1);
	DFS(state_map, 0, +1, step + 1);
}

int main()
{
	int N, M;
	cin >> N >> M;

	StateMap state_map(N, M);
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> state_map.map[r][c];

	//	state_map.print();
	DFS(state_map);
	if (g_goal == 100)
		g_goal = -1;
	cout << g_goal << endl;

	return 0;
}

