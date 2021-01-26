/*
[1727. Largest Submatrix With Rearrangements]
You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

Example 1:

Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m * n <= 105
matrix[i][j] is 0 or 1.

[풀이]
1. 다음과 같이 행 별로 블록의 크기를 구한다.
0 0 1
1 1 1
1 0 1

0 0 1
1 1 2
2 0 3

2. 행 별로 구한 크기로 내림차순 정렬한다.
1 0 0
2 1 1
3 2 0

3. 행 별로 loop를 돌면서 가장 큰 블록 사이즈를 구한다.
1 0 0 --> 1 0 0 : 1
2 1 1 --> 2 2 3 : 3
3 2 0 --> 3 4 0 : 4
*/

// TC: O(NMLogM) : O(N*M + N * (MLogM + M)) : O(NM + NMLogM + NM)
// SC: O(1)
function largestSubmatrix(matrix: number[][]): number {
    for (let i = 1; i < matrix.length; i++) {
        for (let j = 0; j < matrix[i].length; j++) {
            matrix[i][j] = (matrix[i][j] === 1) ? matrix[i - 1][j] + 1 : 0;
        }
    }

    let largest = 0;
    for (const m of matrix) {
        m.sort((a, b) => b - a);
        largest = Math.max(largest, m.reduce((largest, n, i) => Math.max(largest, n * (i + 1)), 0));
    }

    return largest;
};

console.log(largestSubmatrix([[0, 0, 1], [1, 1, 1], [1, 0, 1]]));
// console.log(largestSubmatrix([[1, 0, 1, 0, 1]]));
// console.log(largestSubmatrix([[1, 1, 0], [1, 0, 1]]));
// console.log(largestSubmatrix([[0, 0], [0, 0]]));