#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int> > g_vectors;

int dfs(const int n, const int idx = 0)
{
	if (idx >= n)
		return 0;
	
	int sum = 0;
	int big = 0;
	for (int i=idx; i<n; i++)
	{
		int cost = (i + g_vectors[i].first > n) ? 0 : g_vectors[i].second;
		sum = cost + dfs(n, i + g_vectors[i].first);
		if (sum > big)
			big = sum;
	}
	
	return big;
}

int main(int argc, char* argv[])
{
  int n, a, b;
  cin >>n;
  for (int i=0; i<n; i++)
  {
      cin >>a >>b;
      g_vectors.push_back(make_pair(a, b));
  }
	
	cout << dfs(n, 0) << endl;
	
	return 0;
}