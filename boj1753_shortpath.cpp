#include <iostream>
#include <vector>
#include <queue>

const int MAX_V = 20000;
const int MAX_E = 300000;
const int MAX_W = 10;
const int INF = 99999999;

using namespace std;

struct Vertex 
{
	int id;
	int dist;

	Vertex(int _id, int _dist) : id(_id), dist(_dist) {}
};

struct Road
{
	int dest;
	int dist;

	Road(int _dest, int _dist) : dest(_dest), dist(_dist) {}
};

vector<vector<Road> > map;
vector<int> dist;
vector<int> visit;

struct comp 
{ 
	bool operator () (const Vertex& v1, const Vertex& v2) { return v1.dist > v2.dist; } 
};

priority_queue<Vertex, vector<Vertex>, comp> pq;

int main()
{
	std::ios::sync_with_stdio(false);

	int vcount = 0, ecount = 0;
	int k = 0;
	int u = 0, v = 0, w = 0;

	scanf("%d%d", &vcount, &ecount);
	scanf("%d", &k);
	
	map.resize(vcount + 1);
	visit.resize(vcount + 1);
	dist.resize(vcount + 1);

	for (int i = 0; i < vcount + 1; i++)
		dist[i] = INF;
	dist[k] = 0;

	pq.push(Vertex(k, 0));

	for (int i = 0; i < ecount; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		map[u].push_back(Road(v, w));
	}

	vector<Road>::iterator itr;
	while (pq.empty() == false)
	{
		Vertex cur = pq.top();
		pq.pop();

		if (visit[cur.id] == 1)
			continue;

		visit[cur.id] = 1;
		for (itr = map[cur.id].begin(); itr < map[cur.id].end(); itr++)
		{
			int next = dist[cur.id] + itr->dist;
			if (dist[itr->dest] > next)
			{
				dist[itr->dest] = next;
				pq.push(Vertex(itr->dest, dist[itr->dest]));
			}
		}
	}

	for (int i = 1; i < vcount + 1; i++)
	{
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}