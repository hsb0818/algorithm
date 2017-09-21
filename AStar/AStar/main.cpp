#include <iostream>
#include "Astar.h"

int main()
{
	AStar spf(6, 9);
	spf.RegistVertexToMap(0, 1, 10);
	spf.RegistVertexToMap(0, 2, 30);
	spf.RegistVertexToMap(0, 3, 15);
	spf.RegistVertexToMap(1, 4, 20);
	spf.RegistVertexToMap(2, 5, 5);
	spf.RegistVertexToMap(3, 2, 5);
	spf.RegistVertexToMap(3, 5, 20);
	spf.RegistVertexToMap(4, 5, 20);
	spf.RegistVertexToMap(5, 3, 20);

	spf.Run(0, 5);

	vector<Vertex> path = spf.GetShortestPath(5);
	for (int i = 0; i<path.size(); i++)
		printf("%d -> ", path[i].dest_id);
	printf("\n");

	return 0;
}