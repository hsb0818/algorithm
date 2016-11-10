#include <iostream>
#include <vector>
#include <queue>
/*
	disjoint-set을 이용.
*/
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

typedef queue<Edge> Q_EDGE;
Q_EDGE q_edge;
vector<int> rankset; //Union 최적화를 위해. 루트에 다른 작은 트리를 추가할 때 같은 레벨의 트리이면 랭킹증가
vector<int> parent;

void init(int n)
{
	fill(rankset.begin(), rankset.end(), 0);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
}

int Find(int v) 
{
	if (parent[v] == v)
		return v;

	//함친 후에는 검색할 때 부모를 통일한다
	return parent[v] = Find(parent[v]);
}

void Union(int a, int b)
{
	if (a == b)
		return;

	if (rankset[a] > rankset[b])
		parent[b] = a;
	else if (rankset[a] <= rankset[b])
	{
		parent[a] = b;
		if (rankset[a] == rankset[b])
			rankset[b]++;
	}
}

bool IsLinked(int n)
{
	int prev = Find(1);
	int cur = 0;
	for (int i = 2; i <= n; i++)
	{
		cur = Find(i);
		if (cur != prev)
			return false;

		prev = cur;
	}

	return true;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	parent.resize(n + 1);
	rankset.resize(n + 1);

	int p;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &p);
			if (p == 0)
				continue;

			q_edge.push(Edge(i,j, p));
		}
	}

	//kruskal and disjoint-set
	init(n);
	while (q_edge.empty() == false)
	{
		Edge cur = q_edge.front();
		q_edge.pop();

		int a = Find(cur.v1);
		int b = Find(cur.v2);

		Union(a, b);
	}

	int d;
	for (int i = 0; i < n; i++)
		scanf("%d", &d);

	if (IsLinked(n))
		printf("YES");
	else
		printf("NO");

	return 0;
}