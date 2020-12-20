/*
[350. Intersection of Two Arrays II]
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ctr;
        for (int i : nums1)
            ctr[i]++;
        vector<int> out;
        for (int i : nums2)
            if (ctr[i]-- > 0)
                out.push_back(i);
        return out;
    }
};

void main() {
    vector<int> input1 = { 9, 1, 6, 4 };
    vector<int> input2 = { 1, 4, 9 };

    Solution s;
    vector<int> out = s.intersect(input1, input2);
    for (int n : out)
        cout << n << ",";
}