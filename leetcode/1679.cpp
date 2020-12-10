/*
[1679. Max Number of K-Sum Pairs]

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// TC: O(NLog(N))
// SC: O(N)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> h;

        int opCnt = 0;
        for (int num : nums)
        {
            int diff = k - num;
            unordered_map<int, int>::iterator f = h.find(diff);
            if (f != h.end() && (f->second > 0))
            {
                opCnt++;
                f->second--;
            }
            else
            {
                if (h.find(num) != h.end())
                    h[num]++;
                else
                    h.insert(make_pair(num, 1));
            }
        }

        return opCnt;
    }
};

//void main()
//{
//    vector<int> input = { 2, 5, 4, 4, 1, 3, 4, 4, 1, 4, 4, 1, 2, 1, 2, 2, 3, 2, 4, 2 };
//
//    Solution s;
//    cout << s.maxOperations(input, 3) << endl;
//}