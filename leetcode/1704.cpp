/*
[1704. Determine if String Halves Are Alike]

You are given a 
string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// TC: O(N)
// SC: O(1)
class Solution {
public:
    bool halvesAreAlike(string s) {        
        const int halfSize = (int)(s.length() * 0.5f);
        return getCountVowels(s.substr(0, halfSize)) == getCountVowels(s.substr(halfSize));
    }

    int getCountVowels(const string& s) {
        int vowelCnt[26] = { 0, };
        const int base = ('a' - 'A');

        for (char c : s) {
            c = (c < 'a') ? c + base : c;
            vowelCnt[c - 'a']++;
        }

        int vCnt = 0;
        string vowels = "aeiou";
        for (const char v : vowels) {
            vCnt += vowelCnt[v - 'a'];
        }

        return vCnt;
    }
};

void main() {
    Solution s;
    cout << s.halvesAreAlike("book");
}