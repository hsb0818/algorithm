#include <iostream>

const int INF = 99999999;
const int N = 100;

int map[N + 1][N + 1] = { 0, };
int via[N + 1][N + 1] = { 0, };
int dist[N + 1][N + 1];

int main()
{
	std::ios::sync_with_stdio(false);

	int n = 0, m = 0;
	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}

	int a = 0, b = 0, c = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);

		if (map[a][b] != 0 && map[a][b] < c)
			continue;

		map[a][b] = c;
		dist[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					via[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}

	return 0;
}