/*
[1706. Where Will the Ball Fall]
You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.

풀이
- V자가 되는 순간 -1 반환
- 격자 범위 넘는 순간 -1 반환
- 그외에 이동 지속함
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

// TC: O(M*N)
// SC: O(N)
class Solution {
    int height = 0, width = 0;
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        height = grid.size();
        width = grid[0].size();
        
        vector<int> answer(width, -1);
        for (int c = 0; c < width; c++) {
            answer[c] = dfs(grid, 0, c);
        }

        return answer;
    }

private:
    bool rangeCheck(int r, int c) {
        return (r < height && r >= 0 && c < width && c >= 0);
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r == grid.size())
            return c;
        if (!rangeCheck(r, c))
            return -1;

        // V자면 -1 반환
        if (grid[r][c] == 1 && rangeCheck(r, c + 1) && grid[r][c + 1] == 1) {
            return dfs(grid, r + 1, c + 1);
        }
        else if (grid[r][c] == -1 && rangeCheck(r, c - 1) && grid[r][c - 1] == -1) {
            return dfs(grid, r + 1, c - 1);
        }

        return -1;
    }
};