#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

/*
[70. Climbing Stairs]

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

아래와 같이 규칙을 찾으면 된다
n = 1 --> memo[1] = 1
n = 2 --> memo[2] = 2
n = 3 --> memo[3] = 3 --> memo[3] = memo[2] + memo[1];
n = 4 --> memo[4] = 5 --> memo[3] + memo[2];
    1 1 1 1
    1 1 2
    1 2 1
    2 1 1
    2 2
*/

// TC: O(N)
// SC: O(1)

const int MAX_N = 45;

class Solution {
private:
    int memo[MAX_N + 1] = { 0, 1, 2, };

public:
    int climbStairs(int n) {
        for (int i = 3; i <= n; i++)
            memo[i] = memo[i - 1] + memo[i - 2];

        return memo[n];
    }
};

//void main()
//{
//    Solution s;
//    cout << s.climbStairs(3) << endl;
//}