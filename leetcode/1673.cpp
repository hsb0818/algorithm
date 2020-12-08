/*
Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

Example 1:

Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std; 

// TC: O(N)
// SC: O(K)
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        deque<int> subsStack;

        for (int i = 0; i < nums.size(); i++) {            
            int remainedSize = nums.size() - i; // 앞으로 추가할 수 있는 원소 수

            // 현재 스택에서 마지막 원소를 제외한 수 subsStack.size() - 1
            // stack에서 빼 나가면서 k개를 채울 수 있는 상황을 만든다
            while (!subsStack.empty() && (subsStack.size() - 1) + remainedSize >= k && nums[i] < subsStack.back())
            {
                subsStack.pop_back();
            }
                
            if (subsStack.size() < k) {
                subsStack.push_back(nums[i]);
            }
        }

        return vector<int>(subsStack.begin(), subsStack.end());
    }
};

auto fastIO = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();