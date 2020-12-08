#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std; 

/*
[1675. Minimize Deviation in Array]

You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.

    1. 짝수로는 나눌 수만 있으니까, 일단 홀수에 2를 곱해서 다 짝수로 만든다.
    2. Priority Queue에서 가장 큰 것들을 대상으로 계속해서 2를 나누며 가장 작은 값과의 차이를 비교해나간다.
    * 2로 나누면서 더 작은 값이 나올 수 있다.
        ex) [3, 5]
            1) 10, 6 ---> 6이 작은 값
            2) 6, 5 ---> 5가 작은 값
*/

// TC: O(Nlog(N))
// SC: O(N)
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int, vector<int>, less<int>> pq;

        int minN = numeric_limits<int>::max();
        for (int n : nums)
        {
            n = (n & 1) ? n * 2 : n;
            pq.push(n);
            minN = min(minN, n);
        }

        int minDev = numeric_limits<int>::max(), n = 0;
        while (!(pq.top() & 1))
        {
            n = pq.top() / 2;
            minDev = min(minDev, pq.top() - minN);
            minN = min(minN, n);

            pq.pop();
            pq.push(n);
        }

        return min(minDev, pq.top() - minN);
    }
};

void main()
{
    Solution s;

    vector<int> input = { 4,1,5,20,3 };
    cout << s.minimumDeviation(input) << endl;
}