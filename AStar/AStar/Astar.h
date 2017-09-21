#pragma once

#include <queue>
#include <vector>
#include <math.h>
#include "Vertex.h"

using namespace std;

class AStar
{
public:
	AStar(const int vertex_count, const int edge_count);
	void Init(const int vertex_count, const int edge_count);
	int Run(const int start, const int dest);
	vector<Vertex> GetShortestPath(const int from);
	VertexPos GetVertexPos(const int id) { return m_posmap[id]; }
	void RegistVertexToMap(const int src_id, const int dest_id, const int dist, const bool duplex = false);
	void RegistVertexPosToMap(const int id, const float x, const float y);
	void RemoveEdge(const int src_id, const int dest_id);
	void Clear();

private:
	bool Relax(int& org_val, const int& new_val);
	int GetHeuristic(const int cur, const int dest);

	struct ASC
	{
		bool operator() (const Vertex& v1, const Vertex& v2) 
		{
			return v1.F > v2.F;
		}
	};

private:
	int m_start;
	priority_queue<Vertex, vector<Vertex>, ASC> m_pq;
	vector<vector<Vertex>> m_map;
	vector<VertexPos> m_posmap;
	vector<int> m_visit;
	vector<int> m_dist;
	vector<Vertex> m_prev_path;
};