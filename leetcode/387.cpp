/*
[387. First Unique Character in a String]
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// TC: O(N)
// SC: O(1)
class Solution {
public:
    int firstUniqChar(string s) {
        int check[26] = { 0, };
        for (int i = 0; i < s.length(); i++) {
            ++check[s[i] - 'a'];
        }

        for (int i = 0; i < s.length(); i++) {
            if (check[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};