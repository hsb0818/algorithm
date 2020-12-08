/*
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

Example 2:

Input: accounts = [[1,5],[7,3],[3,5]]
Output: 10
Explanation:
1st customer has wealth = 6
2nd customer has wealth = 10
3rd customer has wealth = 8
The 2nd customer is the richest with a wealth of 10.
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// TC: O(N^2)
// SC: O(1)
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum = 0, wealth = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            sum = 0;
            for (int j = 0; j < accounts[i].size(); j++)
            {
                sum += accounts[i][j];
            }

            wealth = max(wealth, sum);
        }

        return wealth;
    }
};