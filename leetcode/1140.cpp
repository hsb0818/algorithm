#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// TC: O(?)
// SC: O(N^2)
class Solution {
private:
    vector<vector<int>> dp;
    vector<int> sums;
public:
    int stoneGameII(vector<int>& piles) {
        sums.resize(piles.size(), 0);
        sums[piles.size() - 1] = piles.back();
        for (int i = piles.size() - 2; i >= 0; i--)
            sums[i] = sums[i + 1] + piles[i];

        dp.resize(piles.size(), vector<int>(piles.size(), -1));

        return dfs(piles, 0, 1);
    }

    int dfs(vector<int>& piles, int cur, int m) {
        if (cur >= piles.size())
            return 0;
        if (2 * m >= piles.size() - cur)
            return sums[cur];
        if (dp[cur][m] >= 0)
            return dp[cur][m];

        int nextMin = numeric_limits<int>::max();
        for (int i = 1; i <= 2 * m; i++) {
            nextMin = min(nextMin, dfs(piles, cur + i, max(i, m)));
        }

        dp[cur][m] = sums[cur] - nextMin;
        return dp[cur][m];
    }
};

void main() {
	vector<int> input = { 2,7,9,4,4 };
    Solution s;

    cout << s.stoneGameII(input) << endl;
}