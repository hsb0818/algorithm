/*
[28. Implement strStr()]

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().



Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// TC: ÃÖ¾ÇÀÇ °æ¿ì O(haystack.size() * needle.size() - 1)
// SC: O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;

        int M = haystack.length();
        int N = needle.length();
        int startIdx = -1;
        for (int i=0; i<=M - N; i++)
        {
            startIdx = i;
            for (int j = 0; j < N; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    startIdx = -1;
                    break;
                }
            }

            if (startIdx > -1)
                break;
        }

        return startIdx;
    }
};

void main()
{
    Solution s;
    cout << s.strStr("a", "a") << endl;
}