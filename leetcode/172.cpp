/*
[172. Factorial Trailing Zeroes]
Given an integer n, return the number of trailing zeroes in n!.

Follow up: Could you write a solution that works in logarithmic time complexity?

2�� 5�� �� �ֿ� ���ؼ� 0�� �ϳ� �����.
������ 2�� ����� 5�� ������� ����� �����Ƿ�
5�� ����� ������ ����.
������ 5�� ���, 5*5�� ���, 5*5*5�� ��� ... ������ �߰� ����� ����� �Ѵ�.
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