/*
[172. Factorial Trailing Zeroes]
Given an integer n, return the number of trailing zeroes in n!.

Follow up: Could you write a solution that works in logarithmic time complexity?

2와 5의 한 쌍에 대해서 0이 하나 생긴다.
하지만 2의 배수는 5의 배수보다 충분히 많으므로
5의 배수의 개수를 센다.
하지만 5의 배수, 5*5의 배수, 5*5*5의 배수 ... 식으로 추가 배수를 세어야 한다.
5*4 = 20
5*5 * 4 = 100
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// TC: O(Log(N))
// SC: O(1)
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        for (int i = 5; n / i > 0; i *= 5) {
            cnt += n / i;
        }

        return cnt;
    }
};

void main() {
    Solution s;
    cout << s.trailingZeroes(5) << endl;
}