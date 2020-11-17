#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // TC: O(nlog(n))
    // SC: O(n);
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, less<int>> pq;

        for (int i = 0; i < heights.size() - 1; i++) {
            int d = heights[i + 1] - heights[i];

            if (d <= 0)
                continue;

            bricks -= d;
            pq.push(d);

            if (bricks < 0) {
                if (ladders > 0) {
                    ladders--;

                    bricks += pq.top();
                    pq.pop();
                }
                else {
                    return i;
                }
            }
        }

        return heights.size() - 1;
    }
};