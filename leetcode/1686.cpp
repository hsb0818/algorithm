/*
[1686. Stone Game VI]

[Ǯ��]

Alice: [a1, a2, a3]
Bob: [b1, b2, b3]

�̶� �� ��, �� index������ a + b ������ �����Ͽ� Alice -> Bob ������ �����ش�.
a + b = Alice�� Bob�� ���ϴ� ���� �� �̹Ƿ�, ���� ������ ���� ���

A: [1, 2]
B: [3, 1]
--> S: [4, 3] --> �� ���, �����ص� [4, 3]�̴�.

�̷��� �����Ǿ��ٸ�, ù ��°�� Alice�� ������ ���� 0�� ���̴�. a + b�� 4�̱� �����̴�.
Alice ���忡�� 0�� ���� �۰� �������� Bob�� �ְ�� ���� ���ϰ� �ִٴ� ���� �� �� �ִ�.
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// TC: O(NLog(N))
// SC: O(N)
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        const int n = aliceValues.size();
        
        vector<vector<int>> sumHeap(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            sumHeap[i][0] = aliceValues[i] + bobValues[i];
            sumHeap[i][1] = aliceValues[i];
            sumHeap[i][2] = bobValues[i];
        }

        sort(sumHeap.begin(), sumHeap.end(), [](const vector<int>& a, const vector<int>& b) -> int { return a[0] > b[0]; });

        int aliceSum = 0, bobSum = 0;
        bool isAliceTurn = true;
        for (const vector<int>& v : sumHeap) {
            if (isAliceTurn)
                aliceSum += v[1];
            else
                bobSum += v[2];

            isAliceTurn = !isAliceTurn;
        }

        return (aliceSum > bobSum) ? 1 : (aliceSum == bobSum) ? 0 : -1;
    }
};

void main() {
    vector<int> aliceValues = { 2, 4, 3 };
    vector<int> bobValues = { 1, 6, 7 };
    Solution s;

    cout << s.stoneGameVI(aliceValues, bobValues) << endl;
}