/*
[1. Two Sum]

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// TC: O(N)
// SC: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> h;
        vector<int> indices;

        for (int i = 0; i < nums.size(); i++)
        {
            const int diff = target - nums[i];
            const unordered_map<int, int>::iterator founded = h.find(diff);
            if (founded != h.end())
            {
                indices.push_back(founded->second);
                indices.push_back(i);

                break;
            }

            h.insert(make_pair(nums[i], i));
        }

        return indices;
    }
};