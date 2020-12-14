/*
[198. House Robber]
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.



Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int dp[100] = { 0, };
public:
    int rob(vector<int>& nums) {
        fill(dp, dp + 100, -1);
        return dfs(nums, 0);
    }

    // 1.현재 집을 터는 경우와 
    // 2.현재 집을 털지 않고 다음 집을 확인하는 경우에 대한 DFS
    int dfs(vector<int>& nums, int current) {
        if (current >= nums.size()) {
            return 0;
        }

        if (dp[current] >= 0) {
            return dp[current];
        }

        int result = max(dfs(nums, current + 2) + nums[current], dfs(nums, current + 1));
        dp[current] = result;

        return result;
    }
};

void main() {
    Solution s;
    vector<int> input = { 2,7,9,3,1 };
    cout << s.rob(input) << endl;
}