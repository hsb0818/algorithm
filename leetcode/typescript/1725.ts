/*
[1725. Number Of Rectangles That Can Form The Largest Square]
You are given an array rectangles where rectangles[i] = [li, wi] represents the ith rectangle of length li and width wi.

You can cut the ith rectangle to form a square with a side length of k if both k <= li and k <= wi. For example, if you have a rectangle [4,6], you can cut it to get a square with a side length of at most 4.

Let maxLen be the side length of the largest square you can obtain from any of the given rectangles.

Return the number of rectangles that can make a square with a side length of maxLen.

Example 1:
Input: rectangles = [[5,8],[3,9],[5,12],[16,5]]
Output: 3
Explanation: The largest squares you can get from each rectangle are of lengths [5,3,5,5].
The largest possible square is of length 5, and you can get it out of 3 rectangles.

Example 2:
Input: rectangles = [[2,3],[3,7],[4,3],[3,7]]
Output: 3

[풀이]
정사각형으로 잘랐을 때 변의 길이가 가장 긴 순서대로 정렬하고
가장 긴 길이를 가진 원소가 몇개가 있는가
*/

// TC: O(NLogN)
// SC: O(1)
function countGoodRectangles(rectangles: number[][]): number {
    rectangles.sort((a, b) => {
        const [la, wa] = a;
        const [lb, wb] = b;

        return Math.min(lb, wb) - Math.min(la, wa);
    });

    const [l0, w0] = rectangles[0];
    const maxLen = Math.min(l0, w0);

    return rectangles
        .reduce((ac, [li, wi]) => (ac + (Math.min(li, wi) === maxLen ? 1 : 0)), 0);
};

console.log(countGoodRectangles([[2, 3], [3, 7], [4, 3], [3, 7]]));
//console.log(countGoodRectangles([[5, 8], [3, 9], [5, 12], [16, 5]]));