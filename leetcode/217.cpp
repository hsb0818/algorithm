/*
[217. Contains Duplicate]

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<unordered_map>

using namespace std;

// TC: O(N)
// SC: O(N)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> dmap;

        for (int num : nums)
        {
            if (dmap.find(num) != dmap.end()) {
                return true;
            }

            dmap.insert(make_pair(num, 1));
        }

        return false;
    }
};