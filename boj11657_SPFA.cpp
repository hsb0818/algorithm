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

		/*	�̷� ������ ť�� �ִ��� �˻��ϴ� ������ ���ʿ��� ������ ���̱� ���ؼ��̴�.
		*	�̹� ť�� A ������ �ִٰ� �ϸ�, � ������ ���� A �����ص� A�� �湮�ϱ⸸ �ϸ�
		*	���ݱ��� ���ŵ� A���� ���� ���� �ֺ����� ������ ���̱� �����̴�.
		*	�׷��� ���� ť�� �ִ��� üũ���� �ʰ� ���ŵǴ� ��� ���� ť�� �߰����� �ʾƵ� �Ǵ� ���̴�.
		*	���� ����Ŭ�� ��� �� ������ n�� �̻� �����ϰ� �Ǹ� ���� ����Ŭ�� �Ǵ��Ѵ�.
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