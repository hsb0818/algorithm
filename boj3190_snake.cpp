#include <iostream>
#include <deque>
#include <queue>

#define _USE_MATH_DEFINES
#include <math.h>
//#include <Windows.h>

using namespace std;

const int MAX = 101;
const int APPLE = 2;
const int NONE = 0;
const int BODY = 1;
const int cos90[4] = { 1, 0, -1, 0 };
const int sin90[4] = { 0, 1, 0, -1 };

struct Pos2
{
	int x, y;
	Pos2(const int x = 0, const int y = 0)
		: x(x)
		, y(y)
	{}
};

void Draw(const int(&map)[MAX][MAX],
	const int N,
	const deque<Pos2>& body)
{
	system("cls");
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cout << " " << map[r][c] << " ";
		}

		cout << endl;
	}
}

int main()
{
	int map[MAX][MAX] = { NONE, };
	queue<pair<int, char> > msg_q;
	deque<Pos2> body;
	int N, k;

	cin >> N;
	if (N < 2 || N > 100)
		return 0;
	
	cin >> k;
	if(k < 0 || k > 100)
		return 0;

	int a, b;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		map[a - 1][b - 1] = APPLE;
	}

	int L;
	cin >> L;
	if (L < 1 || L > 100)
		return 0;

	int X;
	char C;
	for (int i = 0; i < L; i++)
	{
		cin >> X >> C;
		msg_q.push(make_pair(X, C));
	}

	// x, y
	pair<int, char> msg = msg_q.front();
	msg_q.pop();

	body.push_back(Pos2(0, 0));
	map[body[0].y][body[0].x] = BODY;

	Pos2 dir;
	int time = 1;
	for(;;time++)
	{
		int nextx = body[0].x + cos90[dir.x];
		int nexty = body[0].y + sin90[dir.y];

		if (nextx >= N || nexty >= N ||
			nextx < 0 || nexty < 0 || map[nexty][nextx] == BODY)
			break;
		else if (map[nexty][nextx] == NONE)
		{
			map[body.back().y][body.back().x] = NONE;
			body.pop_back();
		}

		body.push_front(Pos2(nextx, nexty));		
		map[body[0].y][body[0].x] = BODY;

//		cout << "msg : time = " << msg.first << ":" << time << endl;
		if (msg.first == time)
		{
			dir.x = (dir.x + ((msg.second == 'L') ? 3 : 1)) % 4;
			dir.y = (dir.y + ((msg.second == 'L') ? 3 : 1)) % 4;
			
			if (!msg_q.empty())
			{ 
				msg = msg_q.front();
				msg_q.pop();
			}
		}

//		Draw(map, N, body);		
//		Sleep(500);
	}

	cout << time << endl;
	return 0;
}