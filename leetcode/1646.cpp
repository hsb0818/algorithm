#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// TC: O(n/2)
// SC: O(n)
class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums(n + 3);
        nums[0] = 0;
        nums[1] = 1;

        if (n < 2) {
            return nums[n];
        }

        int maxGen = 0;
        for (int i = 1; i*2 <= n; i++) {
            nums[i * 2] = nums[i];
            maxGen = max(maxGen, nums[i * 2]);

            if (i * 2 + 1 > n) {
                break;
            }

            nums[i * 2 + 1] = nums[i] + nums[i + 1];
            maxGen = max(maxGen, nums[i * 2 + 1]);
        }

        return maxGen;
    }
};

//void main() {
//    Solution s;
//    cout << s.getMaximumGenerated(15) << endl;
//}