#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <vector<int> > map;
stack<int> visit;
vector<int> visited;

int dfs(int start);
int next(int src, int start);

int main()
{	
	std::ios::sync_with_stdio(false);

	int n = 0, m = 0;
	scanf("%d%d", &n, &m);

	visited.resize(n + 1);
	map.resize(n + 1);

	int a = 0, b = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		map[b].push_back(a);
	}

	int max = 0;
	vector<int> list;
	list.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		list[i] = dfs(i);
		if (list[i] > max)
			max = list[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (list[i] != max)
			continue;

		printf("%d ", i);
	}

	return 0;
}

int dfs(int start)
{
	visit.push(start);
	visited[start] = start;

	int dist = 0;
	int cur = start;
	while (true)
	{
		cur = next(cur, start);
		if (cur == -1)
		{
			visit.pop();
			if (visit.empty())
				break;

			cur = visit.top();
			continue;
		}

		visit.push(cur);
		visited[cur] = start;
		dist++;
	}

	return dist;
}

int next(int src, int start)
{
	vector<int>::iterator itr;
	for (itr = map[src].begin(); itr < map[src].end(); itr++)
	{
		if (visited[*itr] == start)
			continue;

		return *itr;
	}

	return -1;
}