#include <iostream>
#include <vector>
/*
disjoint-set을 이용.
*/
using namespace std;

struct Edge
{
	int v1;
	int v2;

	Edge(int _v1 = 0, int _v2 = 0)
		: v1(_v1)
		, v2(_v2)
	{}
};

vector<int> rankset; //Union 최적화를 위해. 루트에 다른 작은 트리를 추가할 때 같은 레벨의 트리이면 랭킹증가
vector<int> parent;

void Init(int n)
{
	fill(rankset.begin(), rankset.end(), 0);
	for (int i = 0; i <= n; i++)
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
	a = Find(a);
	b = Find(b);

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

bool IsInGroup(int a, int b)
{
	return Find(a) == Find(b);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	parent.resize(n + 1);
	rankset.resize(n + 1);

	int op, u, v;
	Init(n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &op, &u, &v);
		if (op == 0)
			Union(u, v);
		else
		{
			if (IsInGroup(u, v))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}