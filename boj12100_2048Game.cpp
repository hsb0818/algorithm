#include <iostream>

const int MAX = 21;

using namespace std;

struct StateMap
{
	int map[MAX][MAX] = { 0, };

	void print(const int N)
	{
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				printf("%4d", map[r][c]);
			}

			cout << endl;
		}

		cout << endl;
	}

	const int GetHigh(const int N)
	{
		int high = 0;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				if (map[r][c] > high)
					high = map[r][c];
			}
		}

		return high;
	}

	bool IsLast(const int v, const int N) { return (v != -1) && (v != N); }
	// + : down, right
	// - : up, left
	void Control(const int h, const int v, const int N)
	{
		int chk[MAX][MAX] = { 0, };

		if (h == 0)
		{
			int last = (v < 0) ? 0 : N - 1;
			for (int c = 0; c < N; c++)
			{
				for (int r = last - v; IsLast(r, N); r -= v)
				{
					if (map[r][c] == 0)
						continue;

					int i = r;
					while (true)
					{
						i += v;
						if (i == last && (map[i][c] == 0))
						{
							map[i][c] = map[r][c];
							map[r][c] = 0;
							break;
						}
						else if ((chk[i][c] == 0) && (map[i][c] == map[r][c]))
						{
							chk[i][c] = 1;
							map[i][c] += map[r][c];
							map[r][c] = 0;
							break;
						}
						else if (map[i][c] != 0)
						{
							map[i - v][c] = map[r][c];
							if (i - v != r)
								map[r][c] = 0;

							break;
						}
					}
				}
			}
		}
		else if (v == 0)
		{
			int last = (h < 0) ? 0 : N - 1;
			for (int r = 0; r < N; r++)
			{
				for (int c = last - h; IsLast(c, N); c -= h)
				{
					if (map[r][c] == 0)
						continue;

					int i = c;
					while (true)
					{
						i += h;
						if (i == last && (map[r][i] == 0))
						{
							map[r][i] = map[r][c];
							map[r][c] = 0;
							break;
						}
						else if ((chk[r][i] == 0) && map[r][i] == map[r][c])
						{
							chk[r][i] = 1;
							map[r][i] += map[r][c];
							map[r][c] = 0;
							break;
						}
						else if (map[r][i] != 0)
						{
							map[r][i - h] = map[r][c];
							if (i-h != c)
								map[r][c] = 0;

							break;
						}
					}
				}
			}
		}
	}
};

int high = 0;
void DFS(StateMap state_map, const int N, const int h = 0, const int v = 0, const int step = 0)
{
	if (h != 0 || v != 0)
		state_map.Control(h, v, N);

	if (step >= 5)
	{
		int val = state_map.GetHigh(N);
		if (val > high)
		{
			high = val;
//			state_map.print(N);
		}

		return;
	}

	DFS(state_map, N, -1, 0, step + 1);
	DFS(state_map, N, +1, 0, step + 1);
	DFS(state_map, N, 0, -1, step + 1);
	DFS(state_map, N, 0, +1, step + 1);
}

int main()
{
	int N;
	cin >> N;

	StateMap state_map;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> state_map.map[r][c];

	DFS(state_map, N);
	cout << high << endl;

	return 0;
}

