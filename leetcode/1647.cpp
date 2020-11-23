#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// TC: O(N)
// SC: O(N)
class Solution {
public:
    int minDeletions(string s) {
        int freqs[26] = { 0, };

        for (char c : s) {
            freqs[c - 'a']++;
        }

        int delCnt = 0;
        set<int> goods;
        for (int i = 0; i < 26; i++) {
            int freq = freqs[i];

            while (freq > 0 && !goods.insert(freq).second) {
                freq--;
                delCnt++;
            }
        }

        return delCnt;
    }
};

//void main() {
//    Solution s;
//    cout << s.minDeletions("aaabbbcc") << endl;
//}