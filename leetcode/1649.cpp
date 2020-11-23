#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// TC: O(2N Log(N))
// SC: O(N)
class Solution {
private:
    static const int MAX_VALUE = 1e5 + 1;
    int bit[MAX_VALUE];

public:
    int createSortedArray(vector<int>& instructions) {
        fill(bit, bit + MAX_VALUE, 0);

        int res = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < instructions.size(); ++i) {
            // min(���� �� ���� ������ ���� ����, ���� �� ���� ������ ������ ����)
            // cout << "min(" << get(instructions[i] - 1) << "," << i - get(instructions[i]) << ")" << endl;

            int prevElementCount = intervalSum(instructions[i] - 1);
            int nextElementCount = i - intervalSum(instructions[i]);
            res = (res + min(prevElementCount, nextElementCount)) % mod;
            update(instructions[i]);
        }

        return res;
    }

private:   
    // O(Log(N))
    void update(int x) {
        while (x < MAX_VALUE) {
            // x�� ����� ������ �������� ������Ʈ�Ѵ�
            bit[x]++;
            x += x & -x;
        }
    }

    // O(Log(N))
    int intervalSum(int x) {
        int res = 0;

        while (x > 0) {
            // �������� ���س�����

            res += bit[x];
            x -= x & -x;
        }

        return res;
    }
};

//void main() {
//    Solution s;
//    vector<int> instructions = {1, 5, 6, 2};
//    cout<< s.createSortedArray(instructions) <<endl;
//}