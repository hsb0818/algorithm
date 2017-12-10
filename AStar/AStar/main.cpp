#include <iostream>
#include <time.h>
#include "Astar.h"
#include "Dijikstra.h"

#define SIZE 512
#define V 200
#define W 20
#define START 10
#define DEST 200

int main()
{
	Dijikstra dspf(SIZE, SIZE);
	AStar spf(SIZE, SIZE);
	for (int y = 0; y<V; y++)
	{
		for (int x = 0; x<V; x++)
		{
			dspf.RegistVertexPosToMap(y * 4 + x, x, y);
			spf.RegistVertexPosToMap(y * 4 + x, x, y);
		}
	}

	for (int y = 0; y<V-1; y++)
	{
		for (int x = 0; x<V-1; x++)
		{
			spf.RegistVertexToMap(y * 4 + x, (y + 1) * 4 + x, rand()%W, true);
			spf.RegistVertexToMap(y * 4 + x, y * 4 + (x + 1), rand()%W, true);

			dspf.RegistVertexToMap(y * 4 + x, (y + 1) * 4 + x, rand() % W, true);
			dspf.RegistVertexToMap(y * 4 + x, y * 4 + (x + 1), rand() % W, true);
		}
	}

	cout << "Size : " << V << endl;
	time_t st = clock();
	spf.Run(START, DEST);
	cout << "A* : " << (double)(clock() - st)/CLK_TCK << " time"<<endl;

	st = clock();
	dspf.Run(START, DEST);
	cout<<"Dijkstra : " << (double)(clock() - st) / CLK_TCK << " time" << endl;

	vector<Vertex> path = spf.GetShortestPath(DEST);
	for (int i = 0; i<path.size(); i++)
		printf("%d -> ", path[i].dest_id);
	printf("\n");

	return 0;
}