#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include "Vertex.h"

using namespace std;

struct ASC
{
	bool operator () (const Vertex& v1, const Vertex& v2) { return v1.dist > v2.dist; }
};

class Dijikstra
{
public:
	Dijikstra(const int vertex_count, const int edge_count);
	void RegistVertexToMap(const int src_id, const int dest_id, const int dist, const bool duplex = true);
	void RegistVertexPosToMap(const int id, const float x, const float y);
	VertexPos GetVertexPos(const int id) { return m_posmap[id]; }
	void RemoveEdge(const int src_id, const int dest_id);
	int Run(const int start, const int dest);
	vector<Vertex> GetShortestPath(const int from);
	const vector<int>& GetDistQueue() { return m_dist; }

private:
	void Init(const int vertex_count, const int edge_count);
	void Clear();
	bool Relax(int& org_val, const int& new_val);
	
private:
	int m_start;
	priority_queue<Vertex, vector<Vertex>, ASC> m_pq;
	vector<vector<Vertex> > m_map;
	vector<VertexPos> m_posmap;
	vector<int> m_visit;
	vector<int> m_dist;
	vector<Vertex> m_prev_path;
};
