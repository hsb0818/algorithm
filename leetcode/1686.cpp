/*
[1686. Stone Game VI]

[풀이]

Alice: [a1, a2, a3]
Bob: [b1, b2, b3]

이라 할 때, 각 index에서의 a + b 합으로 정렬하여 Alice -> Bob 순으로 더해준다.
a + b = Alice와 Bob이 평가하는 돌의 값 이므로, 만약 다음과 같은 경우

A: [1, 2]
B: [3, 1]
--> S: [4, 3] --> 이 경우, 정렬해도 [4, 3]이다.

이렇게 구성되었다면, 첫 번째로 Alice가 선택할 것은 0번 돌이다. a + b가 4이기 때문이다.
Alice 입장에선 0번 돌을 작게 평가하지만 Bob은 최고로 높게 평가하고 있다는 것을 알 수 있다.
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