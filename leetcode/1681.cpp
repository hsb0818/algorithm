/*
[1681. Minimum Incompatibility]

You are given an integer array nums​​​ and an integer k. You are asked to distribute this array into k subsets of equal size such that there are no two equal elements in the same subset.

A subset's incompatibility is the difference between the maximum and minimum elements in that array.

Return the minimum possible sum of incompatibilities of the k subsets after distributing the array optimally, or return -1 if it is not possible.

A subset is a group integers that appear in the array with no particular order.

Example 1:

Input: nums = [1,2,1,4], k = 2
Output: 4
Explanation: The optimal distribution of subsets is [1,2] and [1,4].
The incompatibility is (2-1) + (4-1) = 4.
Note that [1,1] and [2,4] would result in a smaller sum, but the first subset contains 2 equal elements.

[풀이]
경우의 수를 찾는 문제이니 DFS라는 것은 알 수 있다.
DFS로 풀어보면 Time limit이 뜨게 되므로 DP Memo를 이용한다.
사용 가능한 index 배열을 미리 구해놔야 하는데, 속도를 위해 bitset을 이용한다
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>

using namespace std;

// TC: O(?)
// SC: O(N*K)
class Solution {
private:
    vector<int> nums;
    vector<pair<int, int>> bitsets;
    vector<vector<int>> dp;
    int upperbound = 0, k = 0;
    const int INF = 1e5;
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        this->nums = nums, this->k = k, this->upperbound = nums.size() / k;

        // 입력에서 중복인 숫자가 k개 초과일 때 -1 반환
        if (!isValidInput(nums, k)) {
            return -1;
        }

        // 전체 선택된 경우 전부 1로 채워진다
        int c = 0;
        int state = (1 << nums.size()) - 1;
        for (int b = 1; b <= state; b++) {
            // 1로 세팅된 비트가 upperbound개 && 중복 원소 bitset이 아닌 경우
            if (getSetBitCount(b) == upperbound && isValidBits(b))
                bitsets.push_back({ b, getMax(b) - getMin(b) }), c++;
        }

        dp.resize(1 << nums.size());
        for (vector<int>& selectVector : dp)
            selectVector = vector<int>(k, -1);

        return dfs(0, 0);
    }

    int dfs(const int state, const int idx)
    {
        if (idx >= k)
            return 0;
        if (dp[state][idx] != -1)
            return dp[state][idx];

        // O(
        // 아예 큰 수를 줘버리고, min 함수에서 걸러지게 한다.
        int res = INF;
        for (const pair<int, int> bitset : bitsets) {
            int bits = bitset.first;
            int diff = bitset.second;

            if ((bits & state) != 0)
                continue;

            res = min(res, dfs(state | bits, idx + 1) + diff);
        }

        dp[state][idx] = res;
        return res;
    }

    int getMin(int mask) {
        int minN = nums.size() + 1;
        for (int i = 0; i < nums.size(); i++) {
            if (mask & (1 << i)) {
                minN = min(minN, nums[i]);
            }
        }

        return minN;
    }
    int getMax(int mask) {
        int maxN = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (mask & (1 << i)) {
                maxN = max(maxN, nums[i]);
            }
        }

        return maxN;
    }

    bool isValidInput(vector<int>& nums, int k)
    {
        unordered_map<int, int> check;
        for (const int num : nums) {
            unordered_map<int, int>::iterator e = check.find(num);
            if (e != check.end()) {
                check[num]++;

                if (check[num] > k) {
                    return false;
                }
            }
            else {
                check.insert(make_pair(num, 1));
            }
        }

        return true;
    }

    bool isValidBits(int mask) {
        unordered_map<int, bool> seen;
        for (int i = 0; i < nums.size(); i++) {
            if (mask & (1 << i)) {
                if (seen.count(nums[i])) return false;
                seen[nums[i]] = true;
            }
        }
        return true;
    }

    int getSetBitCount(int bits) {
        int cnt = 0;
        for (int i = bits; i > 0; i >>= 1) {
            if ((i & 1) == 1)
                cnt++;
        }

        return cnt;
    }
};

void main()
{
    vector<int> input = { 12, 5, 16, 7, 13, 4, 3, 14, 4, 11, 8, 6, 6, 1, 15, 12 };

    Solution s;
    cout << s.minimumIncompatibility(input, 4) << endl;
}