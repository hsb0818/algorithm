#include "Astar.h"

AStar::AStar(const int vertex_count, const int edge_count)
	: m_start(0)
{
	Init(vertex_count, edge_count);
}

void AStar::Init(const int vertex_count, const int edge_count)
{
	m_posmap.resize(vertex_count + 1);
	m_map.resize(vertex_count + 1);
	m_visit.resize(vertex_count + 1);
	m_dist.resize(vertex_count + 1);
	m_prev_path.resize(vertex_count + 1);

	for (int i = 0; i < m_dist.size(); i++)
		m_dist[i] = INF;
}

void AStar::RegistVertexToMap(const int src_id, const int dest_id, const int dist, const bool duplex)
{
	m_map[src_id].push_back(Vertex(dest_id, dist));

	if (duplex)
		m_map[dest_id].push_back(Vertex(src_id, dist));
}

void AStar::RegistVertexPosToMap(const int id, const float x, const float y)
{
	m_posmap[id] = VertexPos(x, y);
}

void AStar::RemoveEdge(const int src_id, const int dest_id)
{
	int i = 0;
	for (; i<m_map[src_id].size(); i++)
	{
		if (dest_id == m_map[src_id][i].dest_id)
			break;
	}

	printf("%d edge removed!\n", m_map[src_id][i]);
	m_map[src_id].erase(m_map[src_id].begin() + i);

	for (int j = 0; j<m_map[src_id].size(); j++)
		printf("---%d edges left\n", m_map[src_id][j]);
}

bool AStar::Relax(int& org_val, const int& new_val)
{
	if (org_val > new_val)
	{
		org_val = new_val;
		return true;
	}

	return false;
}

int AStar::GetHeuristic(const int cur, const int dest)
{
	return sqrt(pow(m_posmap[dest].x - m_posmap[cur].x, 2) + 
		pow(m_posmap[dest].y - m_posmap[cur].y, 2));
}

int AStar::Run(const int start, const int dest)
{
	m_start = start;
	m_dist[start] = 0;
	m_pq.push(Vertex(start, 0));
	
	int dist = 0;
	vector<Vertex>::iterator itr;
	while (m_pq.empty() == false)
	{
		Vertex cur = m_pq.top();
		m_pq.pop();

		if (m_visit[cur.dest_id] == 1)
			continue;

		m_visit[cur.dest_id] = 1;

		for (itr = m_map[cur.dest_id].begin(); itr != m_map[cur.dest_id].end(); itr++)
		{
			if (m_visit[itr->dest_id] == 1)
				continue;

			if (Relax(m_dist[itr->dest_id], m_dist[cur.dest_id] + itr->dist))
			{
				Vertex v = *itr;
				const int G = m_dist[itr->dest_id];
				const int H = GetHeuristic(cur.dest_id, dest);
//				printf("%d, G: %d, H : %d\n", itr->dest_id, G, H);
				v.F = G + H;

				m_pq.push(v);
				m_prev_path[itr->dest_id] = cur;
			}
		}
	}

	if (dest >= 0)
		return m_dist[dest];
	else
		return 0;
}

vector<Vertex> AStar::GetShortestPath(const int from)
{
	deque<Vertex> deq;

	int back = from;
	while (true)
	{
		deq.push_front(m_prev_path[back]);
		back = m_prev_path[back].dest_id;
		if (back == m_start)
			break;
	}

	vector<Vertex>::iterator itr = m_map[m_prev_path[from].dest_id].begin();
	for (; itr != m_map[m_prev_path[from].dest_id].end(); itr++)
	{
		if (itr->dest_id != from)
			continue;

		deq.push_back(Vertex(itr->dest_id, itr->dist));
		break;
	}

	return vector<Vertex>({ deq.begin(), deq.end() });
}

void AStar::Clear()
{
	m_prev_path = vector<Vertex>();
	m_prev_path.resize(m_visit.size());


	for (int i = 0; i<m_visit.size(); i++)
	{
		m_visit[i] = 0;
	}


	for (int i = 0; i < m_dist.size(); i++)
		m_dist[i] = INF;
}