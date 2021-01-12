/*
[1712. Ways to Split Array Into Three Subarrays]
A split of an integer array is good if:

The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.

Example 1:

Input: nums = [1,1,1]
Output: 1
Explanation: The only good way to split nums is [1] [1] [1].
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

/*
S: prefix sums from left.

1. S[j] >= 2S[i] --> S[j] - S[i] >= S[i] --> S[i] <= S[j]/2
2. S[j] <= (S[N-1] + S[i])/2 --> S[j] - S[i] <= S[N-1] - S[j]
 j�� �����Ǿ��� ��, �ش� �κ���(MidSum: S[j] - S[i])�� ������ �ִ밪�� MidSum <= S[N-1] - S[j]�� �����ϴ� �ִ밪�̴�.
 
 start j: Min MidSum
 end j: Max MidSum

 �׷��ٸ� i�� �����Ǿ��� �� ������ Midsum�� ������ 
 end j - start j + 1�̴�.

A: [1,2,2,2,5,0]
S: [1,3,5,7,12,12]

i:0, start j:1, end j:2
- [1],[2],[2,2,5,0]
- [1],[2,2],[2,5,0]
-> end j - start j + 1 = 2

i:1, start j:3, end j:3
- [1,2],[2,2],[2,5,0]
-> end j - start j + 1 = 1
*/

// TC: O(N) : sj, k�� ���ϱ� ���� loop�� �Ź� 0���� �ʱ�ȭ���� �ʰ� ���ӵǹǷ�, N*2N�� �ƴ� N+2N�̴�.
// SC: O(N)
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int N = nums.size();
        vector<int> S(N, 0);
        
        S[0] = nums[0];
        for (int i = 1; i < N; i++)
            S[i] = nums[i] + S[i - 1];

        int total = 0;
        for (int i = 0, sj = 0, k = 2; i < N - 2; i++) {
            // sj�� i ���϶�� �ݵ�� ���� ����
            while (sj <= i || (sj < N - 1 && S[sj] < 2 * S[i])) sj++;

            // k�� sj �̸��̶�� �ݵ�� ���� ����
            // �̷��� rightSum�� ���� index�� ���ϰ� �ǹǷ�, k�� �Ѵ�.
            // ej = k - 1�� �Ǵ� ���̴�.
            while (k < sj || (k < N - 1 && (S[k] - S[i] <= S[N - 1] - S[k]))) k++;

            total = (total + k - sj) % 1000000007;
            cout << i << "," << sj << "," << k << " ---> total = " << total << endl;
        }

        return total;
    }
};

//void main() {
//    //    vector<int> input = { 1,2,2,2,5,0 };
//    vector<int> input = { 8892, 2631, 7212, 1188, 6580, 1690, 5950, 7425, 8787, 4361, 9849, 4063, 9496, 9140, 9986, 1058, 2734, 6961, 8855, 2567, 7683, 4770, 40, 850, 72, 2285, 9328, 6794, 8632, 9163, 3928, 6962, 6545, 6920, 926, 8885, 1570, 4454, 6876, 7447, 8264, 3123, 2980, 7276, 470, 8736, 3153, 3924, 3129, 7136, 1739, 1354, 661, 1309, 6231, 9890, 58, 4623, 3555, 3100, 3437 };
//    Solution s;
//    cout << s.waysToSplit(input) << endl;
//}