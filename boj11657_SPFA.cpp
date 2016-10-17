#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 99999999;

struct Vertex
{
	int dest;
	int w;

	Vertex(int _dest, int _w)
		: dest(_dest), w(_w)
	{}
};

vector<vector<Vertex> > map;
vector<int> dist;
vector<bool> visited;
queue<Vertex> q;

bool spfa(int start, int n);

int main()
{
	int n = 0, m = 0;

	scanf("%d%d", &n, &m);
	map.resize(n + 1);
	dist.resize(n + 1);
	visited.resize(n + 1);
	fill(dist.begin(), dist.end(), INF);
	fill(visited.begin(), visited.end(), false);

	int u = 0, v = 0, w = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		map[u].push_back(Vertex(v, w));
	}

	if (spfa(1, n) == false)
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

bool spfa(int start, int n)
{
	fill(visited.begin(), visited.end(), false);
	vector<Vertex>::iterator itr;
	bool is_updated = false;

	vector<int> cnt;
	cnt.resize(n + 1);
	fill(cnt.begin(), cnt.end(), 0);

	int level = 0;
	dist[start] = 0;
	visited[start] = true;
	q.push(Vertex(start, 0));
	while (q.empty() == false)
	{
		int from = q.front().dest;
		q.pop();

		/*	이런 식으로 큐에 있는지 검사하는 이유는 불필요한 연산을 줄이기 위해서이다.
		*	이미 큐에 A 정점이 있다고 하면, 어떤 순서로 정점 A 갱신해도 A를 방문하기만 하면
		*	지금까지 갱신된 A로의 값을 토대로 주변값을 갱신할 것이기 때문이다.
		*	그러니 굳이 큐에 있는지 체크하지 않고 갱신되는 모든 것을 큐에 추가하지 않아도 되는 것이다.
		*	음수 사이클은 어느 한 지점을 n번 이상 갱신하게 되면 음수 사이클로 판단한다.
		*/	
		visited[from] = false;
		for (itr = map[from].begin(); itr < map[from].end(); itr++)
		{
			if (dist[itr->dest] > dist[from] + itr->w)
			{
				dist[itr->dest] = dist[from] + itr->w;
				if (visited[itr->dest] == false)
				{
					q.push(*itr);
					visited[itr->dest] = true;
					cnt[itr->dest] += 1;
					if (cnt[itr->dest] >= n)
						return false;
				}
			}
		}
	}

	return true;
}