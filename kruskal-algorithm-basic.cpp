#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
	int v1;
	int v2;
	int w;

	Edge(int _v1 = 0, int _v2 = 0, int _w = 0)
		: v1(_v1)
		, v2(_v2)
		, w(_w)
	{}
};

struct comp
{
	bool operator () (const Edge& v1, const Edge& v2) { return v1.w > v2.w; }
};

priority_queue<Edge, vector<Edge>, comp> pq;
vector<int> parent;
vector<int> coast;

int find(int v);
void union_group(int a, int b);

int main()
{
	int n, m;
	int money;
	scanf("%d%d", &n, &m);
	parent.resize(n + 1);
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	coast.resize(n + 1);
	fill(coast.begin(), coast.end(), 0);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &money);
		coast[i] = money;
	}

	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		pq.push(Edge(u, v, w * 2 + coast[u] + coast[v]));
	}

	int dist = 0;
	while (pq.empty() == false)
	{
		const Edge cur = pq.top();
		pq.pop();

		int a = find(cur.v1);
		int b = find(cur.v2);

		if (a == b)
			continue;

		union_group(a, b);
		dist += cur.w;
	}

	printf("%d\n", dist);

	return 0;
}

int find(int v)
{
	if (parent[v] == v)
		return v;

	return find(parent[v]);
}

void union_group(int a, int b)
{
	parent[a] = b;
}