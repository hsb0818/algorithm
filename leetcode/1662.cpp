/*
Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.

Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// TC: O(N) : O(2N)
// SC: O(N) : O(N)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return getStringFromArray(word1) == getStringFromArray(word2);
    }

    string getStringFromArray(vector<string>& word) {
        string sum;
        for (string s : word) {
            sum += s;
        }

        return sum;
    }
};