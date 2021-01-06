/*
[1711. Count Good Meals]
A good meal is a meal that contains exactly two different food items with a sum of deliciousness equal to a power of two.

You can pick any two different foods to make a good meal.

Given an array of integers deliciousness where deliciousness[i] is the deliciousness of the i​​​​​​th​​​​​​​​ item of food, return the number of different good meals you can make from this list modulo 109 + 7.

Note that items with different indices are considered different even if they have the same deliciousness value.

Example 1:

Input: deliciousness = [1,3,5,7,9]
Output: 4
Explanation: The good meals are (1,3), (1,7), (3,5) and, (7,9).
Their respective sums are 4, 8, 8, and 16, all of which are powers of 2.
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
private:
    const int M = 1000000007;
public:
    int countPairs(vector<int>& deliciousness) {    
        sort(deliciousness.begin(), deliciousness.end());

        unordered_map<int, int> ht;
        ht[deliciousness[0]]++;

        int result = 0;
        for (int i = 1; i < deliciousness.size(); i++) {
            for (int p = 0; p <= 21; p++) {
                const int bin = (int)pow(2, p);
                // deliciousness를 정렬해 두었으므로, 현재 값 기준으로 현재 값 *2보다 큰 2의 승수는 볼 필요가 없다.
                if (bin > (2 * deliciousness[i]))
                    break;

                const int diff = bin - deliciousness[i];               
                if (ht.find(diff) != ht.end()) {
                    result = (result + ht[diff]) % M;
                }
            }

            ht[deliciousness[i]]++;
        }

        return result;
    }
};

void main() {
    Solution s;
    vector<int> input = { 1,3,5,7,9 };
    cout << s.countPairs(input) << endl;
}