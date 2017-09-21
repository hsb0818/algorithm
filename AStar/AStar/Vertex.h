#pragma once

#define INF	99999999

struct Vertex
{
	int dest_id;
	int dist;
	int F;

	Vertex() { }
	Vertex(const int _dest_id, const int _dist)
		: dest_id(_dest_id)
		, dist(_dist)
		, F(0)
	{
	}
};

struct VertexPos
{
	int x;
	int y;
	VertexPos() {}
	VertexPos(const int _x, const int _y)
		: x(_x)
		, y(_y)
	{
	}
};