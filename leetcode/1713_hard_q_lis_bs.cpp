/*
[1713. Minimum Operations to Make a Subsequence]
You are given an array target that consists of distinct integers and another integer array arr that can have duplicates.

In one operation, you can insert any integer at any position in arr. For example, if arr = [1,4,1,2], you can add 3 in the middle and make it [1,4,3,1,2]. Note that you can insert the integer at the very beginning or end of the array.

Return the minimum number of operations needed to make target a subsequence of arr.

A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

Example 1:

Input: target = [5,1,3], arr = [9,4,2,3,4]
Output: 2
Explanation: You can add 5 and 1 in such a way that makes arr = [5,9,4,1,2,3,4], then target will be a subsequence of arr.

target�� ���Ҹ� �󸶳� ��� �ϴ°�?
- target�� arr�� ���� �� subarray�� ã�� ����. �̰͸� ã���� target.size() - subarray.size() �� ��ȯ�ϸ� �ȴ�.
���� �� subarray�� LIS �˰����� �ִ�. �⺻������ DP�� �̿��� ���� Ǯ����, �̴� O(N^2)�̹Ƿ� TLE�� �߻��Ѵ�.

������ �ڼ��� ���캸�� target�� Distinct integer array��� �Ǿ� �ִ�.
�̴� target�� ���ҵ��� value�� key, index�� value�� �ϴ� �ؽ����̺��� ����� 
index�� arr������ ������ ����� LIS ��� �迭�� ���� �� �ְ� �ȴ�.

���� target = [5,2,2] ��� arr���� 2�� ���� target�� � ��ġ���� �� ���� ���� �����̴�.

LIS �˰��� DP, Binary Search����
- https://hanbi97.tistory.com/189
- https://chanhuiseok.github.io/posts/algo-49
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

// TC: O(NLogN)
// SC: O(N)
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> ht;
        for (int i = 0; i < target.size(); i++)
            ht.insert(make_pair(target[i], i));

        vector<int> lis;
        for (int i = 0; i < arr.size(); i++) {
            if (ht.find(arr[i]) == ht.end())
                continue;

            // lower_bound TC: O(LogN)
            auto it = lower_bound(lis.begin(), lis.end(), ht[arr[i]]);
            if (it == lis.end())
                lis.push_back(ht[arr[i]]);
            else
                *it = ht[arr[i]];
        }

        return target.size() - lis.size();
    }
};

//void main() {
//    //vector<int> target = { 5,1,3 };
//    //vector<int> arr = { 9,4,2,3,4 };
//    vector<int> target = { 6,4,8,1,3,2 };
//    vector<int> arr = { 4,7,6,2,3,8,6,1 };
//    Solution s;
//
//    cout << s.minOperations(target, arr) << endl;
//}