/*
[204. Count Primes]

Count the number of prime numbers less than a non-negative number, n.

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

*/

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

const int MAX_N = 5000001;

// TC: O(NLog(Log(N))
// SC: O(N)
class Solution {
public:
    int countPrimes(int n) {
        vector<int> sieve(MAX_N + 1, 1);

        int count = 0;
        for (int i = 2; i*i <= n; i++)
        {
            if (sieve[i] == 0)
                continue;
            for (int j = i + i; j <= n; j+=i)
                sieve[j] = 0;
        }

        for (int i = 2; i < n; i++)
            count += sieve[i];

        return count;
    }
};

void main()
{
    Solution s;
    cout << s.countPrimes(2) << endl;
}