#include <iostream>
#include <queue>

using namespace std;

const int MAX = 101;

struct Vertex
{
	int x;
	int y;

	Vertex(int _x, int _y) : x(_x), y(_y) {}
};

int bfs(const Vertex& start, const Vertex& dest, int n, int m);
void push(const Vertex& v, int cur);

int map[MAX][MAX] = { 0, };
queue<Vertex> road_queue;

int main()
{
	std::ios::sync_with_stdio(false);

	int n = 0, m = 0;
	char str[MAX] = "";

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		for (int j = 0; j < m; j++)
			map[i][j] = str[j] - '0';
	}

	Vertex start(0, 0);
	Vertex dest(n-1, m-1);

	printf("%d\n", bfs(start, dest, n, m));

	return 0;
}

int bfs(const Vertex& start, const Vertex& dest, int n, int m)
{
	int dist = 1;
	road_queue.push(start);

	while (road_queue.empty() == false)
	{
		Vertex cur = road_queue.front();
		dist = map[cur.x][cur.y];
		if (cur.x == dest.x && cur.y == dest.y)
			break;
		
		road_queue.pop();
		
		if (cur.y > 0 && map[cur.x][cur.y - 1] == 1)
			push(Vertex(cur.x, cur.y - 1), map[cur.x][cur.y]);
		if (cur.y < m && map[cur.x][cur.y + 1] == 1)
			push(Vertex(cur.x, cur.y + 1), map[cur.x][cur.y]);			
		if (cur.x > 0 && map[cur.x - 1][cur.y] == 1)
			push(Vertex(cur.x - 1, cur.y), map[cur.x][cur.y]);
		if (cur.x < n && map[cur.x + 1][cur.y] == 1)
			push(Vertex(cur.x + 1, cur.y), map[cur.x][cur.y]);
	}

	return dist;
}

void push(const Vertex& v, int cur)
{
	road_queue.push(v);
	map[v.x][v.y] = cur + 1;
}