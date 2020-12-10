/*
[1680. Concatenation of Consecutive Binary Numbers]

Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

Example 1:

Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

// TC: O(NLog(N))
// SC: O(1)
const int MOD = 1e9 + 7;
class Solution {
public:
    int concatenatedBinary(int n) {
        long res = 1;

        for (int i = 2; i <= n; i++)
            res = ((res << getBitCount(i)) | i) % MOD;

        return res;
    }

    int getBitCount(int n)
    {
        int cnt = 0;
        for (int i = n; i > 0; i >>= 1)
            cnt++;

        return cnt;
    }
};

void main()
{
    Solution s;
    int res = s.concatenatedBinary(12);
    cout << bitset<32>(res) << endl;
    cout << res << endl;
}