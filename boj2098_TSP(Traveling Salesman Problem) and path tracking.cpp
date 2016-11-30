#include <iostream>
#include <vector>

// DP�� ��Ʈ����ũ�� �̿��� ���ǿ� ����
// �湮 üũ�� ��Ʈ����ũ�� �ϰ�, �̹� ������ Ž���ߴ� ��θ� DP�� ������ �ΰ� ����Ѵ�.
// ��� ������ �������� ������ִٴ� ���� �Ͽ�.. ������ �湮�� ������ ���������� �Ÿ��� ��ȯ�� ������, 
// ����� ���� �� ����Ǿ� ���� ���� ��츦 �Ǻ��ϴ� ���� �ʿ��� �� �ϴ�

using namespace std;

const int INF = 999999999;

int start = 1;
int N;
vector<vector<int> > w;
vector<vector<int> > dp; // dp[1][bit] = 1���������� ���� ��� ��θ� ���� 1������ �Դ°�

int TSP(const int cur, const int visit) 
{
	// �� �湮�ߴٸ� ���� ��ġ(������ ��)���� ������������ �Ÿ��� ��ȯ(��� ������ ������ ���� ��)
	//�������� �湮�� �� 3�̶��, ������ 3���� 1�� ���� ����� �ϳ���. �׷��� �̷��� �� ��.
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
		//next�� �湮�ߴ°�
		if ((visit & (1 << (next - 1))) > 0)
			continue;
		if (w[cur][next] == 0) // �� �� �ִ� ���� ��
			continue;

//		cout << cur << "-" << next << endl;
	
		dist = w[cur][next] + TSP( next, visit | (1 << (next - 1)) );
		min = (min <= dist) ? min : dist;
	}
//	cout << cur << ":" << visit << "->" << min << endl;
	dp[cur][visit] = min;
	return min;
}

/* ��� ����
*	1���� ��� ���ø� �湮�ϰ� 1�� ���ƿ��� �ִܰ�ΰ� 35���, 
*	1���� ������(�� �� �ִ�) ���ñ����� �Ÿ��� �� ���� ������ ��θ� ������ �� �ִ�.
*	���� 1->2�� �����ٸ�, 1->2�� ����ġ(10)�� �� ����. 35-10 = 25�ε�, �׷�
*	dp[2][0011] : 25���� �Ѵ�. �ֳĸ� dp[2][0011]�� 1�� ���ļ� 2�� �԰�, 2���� �ٽ� 1�� ���ư��� ����� �ּҰ��̴�.
*	�ٵ� ���� �� ���� 25�� �ƴ϶�� ó���� 1���� 2�� �ٷ� ���İ��� ���� ���̴�.
*	�̷��� �����ϴ� ������ 1->2 ����ġ�� 2->1 ����ġ�� �ٸ� ��� �����Ͱ� �Է����� ������ �����̴�.
*	�׷��� ���� 4���� ���� �ٸ� ����� ���� �� �ִ� ���̴�.
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