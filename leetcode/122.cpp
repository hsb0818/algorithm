#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

/*
[122. Best Time to Buy and Sell Stock II]

Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

    오늘보다 내일이 비싸면 판다
*/

// TC: O(N)
// SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        
        for (int i = 0; i < prices.size() - 1; i++)
        {
            int profit = prices[i + 1] - prices[i];
            maxProfit = (profit > 0) ? maxProfit + profit : maxProfit;
        }

        return maxProfit;
    }
};

//void main()
//{
//    vector<int> input = { 7,1,5,3,6,4 };
//    Solution s;
//    cout << s.maxProfit(input) << endl;
//}