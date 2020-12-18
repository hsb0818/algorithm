/*
[1690. Stone Game VII]
Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.

Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the score's difference. Alice's goal is to maximize the difference in the score.

Given an array of integers stones where stones[i] represents the value of the ith stone from the left, return the difference in Alice and Bob's score if they both play optimally.

Example 1:

Input: stones = [5,3,1,4,2]
Output: 6
Explanation:
- Alice removes 2 and gets 5 + 3 + 1 + 4 = 13 points. Alice = 13, Bob = 0, stones = [5,3,1,4].
- Bob removes 5 and gets 3 + 1 + 4 = 8 points. Alice = 13, Bob = 8, stones = [3,1,4].
- Alice removes 3 and gets 1 + 4 = 5 points. Alice = 18, Bob = 8, stones = [1,4].
- Bob removes 1 and gets 4 points. Alice = 18, Bob = 12, stones = [4].
- Alice removes 4 and gets 0 points. Alice = 18, Bob = 12, stones = [].
The score difference is 18 - 12 = 6.

[풀이]
최적을 구하는 과정을 보면

Alice 13: 15 - 2 
Bob 8: 13 - 5
Alice 5: 8 - 3
Bob 4: 5 - 1
Alice 0: 4 - 4

Alice는 +, Bob은 -
* 13 - 8 + 5 - 4 + 0 = 13 - (8 - 5 + 4) = 13 - (8 - (5 - 4))
위와 같으며, 아래 2가지 경우가 생긴다.
A. sum - stones[r] - f(l, r - 1, sum - stones[r]) // 오른쪽 고르는 경우
B. sum - stones[l] - f(l + 1, r, sum - stones[l]) // 왼쪽을 고르는 경우

이 코드를 타고들어가면서, 다시 올라오면 결국 위의 2가지 경우에 대해 13 - (8 - (5 - 4)) 같은 식이 만들어지게 되고
둘 중에 차이가 더 

[5,3,1,4,2] sum is 15

A: 13: 15 - 2
B: 9: 13 - 4
A: 8: 9 - 1
B: 5: 8 - 3
A: 0: 5 - 5

13 - 9 + 8 - 5 + 0 = 7


*/

// TC: O(N^2)
// SC: O(N*N)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
public:
    int stoneGameVII(vector<int>& stones) {
        dp.resize(stones.size(), vector<int>(stones.size(), -1));

        int sum = 0;
        for (const int n : stones)
            sum += n;

        return dfs(stones, 0, stones.size() - 1, sum);
    }

    int dfs(const vector<int>& stones, const int l, const int r, const int sum) {
        if (l >= r)
            return 0;
        if (dp[l][r] >= 0) {
            return dp[l][r];
        }

        //cout << "start-- " << l << "," << r << endl;
        int leftResult = sum - stones[l] - dfs(stones, l + 1, r, sum - stones[l]);
        int rightResult = sum - stones[r] - dfs(stones, l, r - 1, sum - stones[r]);

        //cout << leftResult << "," << rightResult << endl;
        //cout << "end-- " << l << "," << r << endl;

        dp[l][r] = max(leftResult, rightResult);

        return dp[l][r];
    }
};

void main() {
    Solution s;
    vector<int> input = { 5,3,1,4,2 };
    cout << s.stoneGameVII(input) << endl;
}