/*
[53. Maximum Subarray]
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

[풀이1]: DFS + DP --> *TLE*

Two Pointer: 2가지 경우에 대해 풀어나간다.

1. 왼쪽 끝을 제거하는 경우
2. 오른쪽 끝을 제거하는 경우

dp[l][r] = l ... r 까지 subarray의 최대 합

[풀이2]: DP only
이전까지의 합을 더해보면서 더 큰지 작은지 확인.

1) 더 작을 경우 합치지 않음
2) 음수가 될 경우 0을 더함
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// TC: O(N^2)
// SC: O(N^2)
/*
class Solution {
private:
    vector<vector<int>> dp;
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        for (const int n : nums)
            sum += n;

        dp.resize(nums.size(), vector<int>(nums.size(), -1));

        return dfs(nums, 0, nums.size() - 1, sum);
    }

    int dfs(vector<int>& nums, int l, int r, int sum) {
        if (l == r)
            return sum;
        if (dp[l][r] >= 0)
            return dp[l][r];
        
        int selLeft = dfs(nums, l + 1, r, sum - nums[l]);
        int selRight = dfs(nums, l, r - 1, sum - nums[r]);

        dp[l][r] = max(sum, max(selLeft, selRight));
        return dp[l][r];
    }
};
*/

// TC: O(N)
// SC: O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);

        int maxSum = dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = nums[i] + ((dp[i - 1] > 0) ? dp[i - 1] : 0);
            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
};

void main() {
    vector<int> input = { -84, -87, -78, -16, -94, -36, -87, -93, -50, -22, -63, -28, -91, -60, -64, -27, -41, -27, -73, -37, -12, -69, -68, -30, -83, -31, -63, -24, -68, -36, -30, -3, -23, -59, -70, -68, -94, -57, -12, -43, -30, -74, -22, -20, -85, -38, -99, -25, -16, -71, -14, -27, -92, -81, -57, -74, -63, -71, -97, -82, -6, -26, -85, -28, -37, -6, -47, -30, -14, -58, -25, -96, -83, -46, -15, -68, -35, -65, -44, -51, -88, -9, -77, -79, -89, -85, -4, -52, -55, -100, -33, -61, -77, -69, -40, -13, -27, -87, -95, -40 };
    Solution s;
    cout << s.maxSubArray(input) << endl;
}