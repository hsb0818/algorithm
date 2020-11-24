#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Ǯ��
 1. ���������κ��� �̸� �հ踦 ���� map�� �����Ѵ�.
 2. �̹� ���� or �������� x���� üũ�Ѵ�
 3. 0���� nums.size() - 1���� ���鼭 �������κ��� ������ �հ踦 ������ map[x - left_sum] ���� �ִ��� ã��, �ִٸ� min�� ���Ѵ�
*/

// TC: O(Log(N))
// SC: O(N)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // balanced tree (b tree)
        // TC: O(Log(N))
        unordered_map<int, int> ac_sums;
        int sum = 0;
        int numCnts = nums.size();

        // O(NLog(N))
        for (int i = numCnts - 1; i >= 0; i--) {
            sum += nums[i];
            ac_sums.insert(make_pair(sum, i));
        }

        if ((nums[0] == x) || (nums[numCnts - 1] == x)) {
            return 1;
        }

        int min_op = INT_MAX;
        int left_sum = 0;
        // O(N)
        for (int l = -1; l < numCnts; l++) {
            if (l >= 0)
                left_sum += nums[l];

            // O(1)
            unordered_map<int, int>::iterator itr = ac_sums.find(x - left_sum);
            if (itr != ac_sums.end() && itr->second > l) {
                int r_idx = itr->second;
                min_op = min(min_op, (l + 1) + (numCnts - r_idx));
            }
        }

        return (min_op == INT_MAX) ? -1 : min_op;
    }
};