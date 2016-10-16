#include <iostream>
#include <vector>

using namespace std;

const int INF = 99999999;

struct Vertex
{
	int src;
	int dest;
	int w;

	Vertex(int _src, int _dest, int _w)
		: src(_src), dest(_dest), w(_w)
	{}
};

vector<Vertex> map;
vector<int> dist;

void bellmanford(int vertex_count);
bool is_exist_cycle(int vertex_count);

int main()
{
	int n = 0, m = 0;

	scanf("%d%d", &n, &m);
	map.reserve(m);

	dist.resize(n + 1);
	fill(dist.begin(), dist.end(), INF);
	dist[1] = 0;

	int u = 0, v = 0, w = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		map.push_back(Vertex(u, v, w));
	}

	bellmanford(n);
	if (is_exist_cycle(n))
	{
		printf("-1\n");
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		if (dist[i] == INF)
			printf("-1\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}

void bellmanford(int vertex_count)
{
	for (int i = 0; i < vertex_count-1; i++)
	{
		for (vector<Vertex>::iterator itr = map.begin(); itr < map.end(); itr++)
		{
			if (dist[itr->src] == INF)
				continue;

			if (dist[itr->dest] > dist[itr->src] + itr->w)
				dist[itr->dest] = dist[itr->src] + itr->w;
		}
	}
}

bool is_exist_cycle(int vertex_count)
{
	for (vector<Vertex>::iterator itr = map.begin(); itr < map.end(); itr++)
	{
		if (dist[itr->dest] > dist[itr->src] + itr->w)
			return true;
	}

	return false;
}