/*
[171. Excel Sheet Column Number]

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
Example 1:

Input: "A"
Output: 1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// TC: O(N)
// SC: O(1)
class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += getNumber(s[i]) * pow(26, (s.length() - 1) - i);
        }

        return sum;
    }

    int getNumber(char c) {
        return c - 'A' + 1;
    }
};

void main() {
    Solution s;
    cout << s.titleToNumber("AAA") << endl;
}