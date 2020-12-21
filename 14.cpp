/*
[14. Longest Common Prefix]
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// TC: O(NLog(N))
// SC: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];

        sort(strs.begin(), strs.end());

        // ���� ������ �ϸ� index 0�� N-1�� ���� ���̰� ū ���ڿ��� �ȴ�.
        string a = strs[0];
        string b = strs[strs.size() - 1];

        return getPrefix(a, b);
    }

    string getPrefix(const string str1, const string str2) {
        string prefix;

        for (int i = 0; i < str1.length() && i < str2.length(); i++) {
            if (str1[i] != str2[i])
                break;

            prefix += str1[i];
        }

        return prefix;
    }
};

void main() {
    Solution s;
    vector<string> input = { "abab","aba","abc" };

    cout << s.longestCommonPrefix(input) << endl;
}