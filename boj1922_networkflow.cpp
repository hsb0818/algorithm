#include <iostream>
#include <queue>
#include <vector>

const int MAX_N = 1000;
const int MAX_M = 100000;

using namespace std;

struct Vertex
{
	int id;
	int dist;

	Vertex(int _id, int _dist) : id(_id), dist(_dist) {}
};

struct comp
{
	bool operator () (const Vertex& v1, const Vertex& v2) { return v1.dist > v2.dist; }
};

priority_queue<Vertex, vector<Vertex>, comp> pq;
vector<vector<Vertex> > map;
vector<int> visit;

int main()
{
	std::ios::sync_with_stdio(false);

	int n = 0, m = 0;
	int u = 0, v = 0, w = 0;

	scanf("%d", &n);
	scanf("%d", &m);

	visit.resize(n + 1);
	map.resize(n + 1);
	pq.push(Vertex(1, 0));

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		map[u].push_back(Vertex(v, w));
		map[v].push_back(Vertex(u, w));
	}

	int dist = 0;
	vector<Vertex>::iterator itr;
	while (pq.empty() == false)
	{
		Vertex cur = pq.top();
		pq.pop();

		if (visit[cur.id] == 1)
			continue;

		visit[cur.id] = 1;

		for (itr = map[cur.id].begin(); itr < map[cur.id].end(); itr++)
		{
			if (visit[itr->id] == 1)
				continue;

			pq.push(Vertex(itr->id, itr->dist));
		}

		dist += cur.dist;
	}

	printf("%d\n", dist);

	return 0;
}