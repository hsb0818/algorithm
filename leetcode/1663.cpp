#include<iostream>
#include<algorithm>

using namespace std;

/*
The numeric value of a lowercase character is defined as its position (1-indexed) in the alphabet, so the numeric value of a is 1, the numeric value of b is 2, the numeric value of c is 3, and so on.

The numeric value of a string consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.

You are given two integers n and k. Return the lexicographically smallest string with length equal to n and numeric value equal to k.

Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.
*/

// TC: O(1)
// SC: O(N)
class Solution {
public:
    string getSmallestString(int n, int k) {
        k -= n;
        int zCnt = k / 25;
        k = k % 25;

        string pre(n - zCnt - ((k != 0) ? 1 : 0), 'a');
        string mid((k != 0) ? 1 : 0, 'a' + k);
        string suf(zCnt, 'z');

        return pre + mid + suf;
    }
};


//void main()
//{
//    Solution s;
//    cout << s.getSmallestString(5, 73) << endl;
//}