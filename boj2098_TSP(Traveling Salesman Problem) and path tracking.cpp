#include <iostream>
#include <vector>

// DP와 비트마스크를 이용한 외판원 문제
// 방문 체크를 비트마스크로 하고, 이미 이전에 탐색했던 경로를 DP로 저장해 두고 사용한다.
// 모든 점들이 시작점과 연결되있다는 가정 하에.. 마지막 방문한 점에서 시작점과의 거리를 반환해 주지만, 
// 제대로 만들 땐 연결되어 있지 않을 경우를 판별하는 식이 필요할 듯 하다

using namespace std;

const int INF = 999999999;

int start = 1;
int N;
vector<vector<int> > w;
vector<vector<int> > dp; // dp[1][bit] = 1번지점에서 에서 어느 경로를 거쳐 1번으로 왔는가

int TSP(const int cur, const int visit) 
{
	// 다 방문했다면 현재 위치(마지막 점)에서 시작점으로의 거리를 반환(모든 점들이 마지막 점이 됨)
	//마지막에 방문한 게 3이라면, 어차피 3에서 1로 가는 방법은 하나다. 그래서 이렇게 해 줌.
	if (visit == ((1 << N) - 1))
	{	
		dp[cur][visit] = w[cur][start];
		return dp[cur][visit];
	}
	if (dp[cur][visit] >= 0)
		return dp[cur][visit];
	
	int min = INF;
	int dist = 0;
	for (int next = 1; next <= N; next++)
	{
		//next를 방문했는가
		if ((visit & (1 << (next - 1))) > 0)
			continue;
		if (w[cur][next] == 0) // 갈 수 있는 길일 때
			continue;

//		cout << cur << "-" << next << endl;
	
		dist = w[cur][next] + TSP( next, visit | (1 << (next - 1)) );
		min = (min <= dist) ? min : dist;
	}
//	cout << cur << ":" << visit << "->" << min << endl;
	dp[cur][visit] = min;
	return min;
}

/* 경로 추적
*	1에서 모든 도시를 방문하고 1로 돌아오는 최단경로가 35라면, 
*	1에서 근접한(갈 수 있는) 도시까지의 거리를 빼 보는 것으로 경로를 추적할 수 있다.
*	만약 1->2로 갔었다면, 1->2의 가중치(10)를 빼 보자. 35-10 = 25인데, 그럼
*	dp[2][0011] : 25여야 한다. 왜냐면 dp[2][0011]은 1을 거쳐서 2로 왔고, 2에서 다시 1로 돌아가는 경로의 최소값이다.
*	근데 만약 이 값이 25가 아니라면 처음의 1에서 2를 바로 거쳐가지 않은 것이다.
*	이렇게 생각하는 이유는 1->2 가중치와 2->1 가중치가 다른 행렬 데이터가 입력으로 들어오기 때문이다.
*	그래서 점이 4개인 경우라도 다른 결과가 나올 수 있는 것이다.
*/
void PrintTrack(int dist)
{
	vector<int> path;
	path.reserve(20);
	path.push_back(1);
	int cur = 1;
	int visit = 1;
	for (int i=0; i<N; i++)
	{
		for (int next = 1; next <= N; next++)
		{
			if ((visit & (1 << (next - 1))) > 0)
				continue;
			
//			cout << cur << ":" << next << endl;
//			cout << dist - w[cur][next] << "|" << dp[next][visit | (1 << (next - 1))] << endl;
			if (dist - w[cur][next] == dp[next][visit | (1 << (next - 1))])
			{
				path.push_back(next);
				dist = dist - w[cur][next];
				cur = next;
				visit = visit | (1 << (next - 1));
			}
		}
	}

	for (vector<int>::iterator itr = path.begin(); itr < path.end(); itr++)
		cout << *itr << "-";
	cout << start << endl;
}

int main()
{
	scanf("%d", &N);
	w.resize(N + 1);
	dp.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		w[i].resize(N + 1);
		dp[i].resize(1 << N, -1);
		for (int j = 1; j <= N; j++)
			scanf("%d", &w[i][j]);
	}

	int min_dist = TSP(start, 1 << (start - 1));
	cout << min_dist << endl;

	PrintTrack(min_dist);
	return 0;
}