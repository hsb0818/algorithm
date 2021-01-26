/*
[1726. Tuple with Same Product]
Given an array nums of distinct positive integers,
return the number of tuples (a, b, c, d) such that a * b = c * d
where a, b, c, and d are elements of nums, and a != b != c != d.

Example 1:

Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
Example 2:

Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valids tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,4,5)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
Example 3:

Input: nums = [2,3,4,6,8,12]
Output: 40

[풀이]
pair 2개가 골라지면, 다음 4가지 경우가 생긴다.
 a * b = c * d
 b * a = c * d
 a * b = d * c
 b * a = d * c

반대의 경우까지 해서 4 * 2가 된다

pair 3개가 골라지면, a,b에 대해 다음 4*2가지가 생긴다.
 a * b = c * d
 b * a = c * d
 a * b = d * c
 b * a = d * c
 a * b = e * f
 b * a = e * f
 a * b = f * e
 b * a = f * e

 ... c,d에 대해 8가지
 ... e,f에 대해 8가지
총 24가지

pair 4개가 골라지면 a,b에 대해 4*3가지가 생긴다.
 a * b = c * d
 b * a = c * d
 a * b = d * c
 b * a = d * c
 a * b = e * f
 b * a = e * f
 a * b = f * e
 b * a = f * e
 a * b = g * h
 b * a = g * h
 a * b = h * g
 b * a = h * g

 ... c,d에 대해 12가지
 ... e,f에 대해 12가지
 ... g,h에 대해 12가지
총 48가지

정리하자면
pair 2: 4 * 1 * 2
pair 3: 4 * 2 * 3
pair 4: 4 * 3 * 4

...를 식으로 하면 4 * (n-1) * n
*/

// TC: O(N^2)
// SC: O(N^2)
function tupleSameProduct(nums: number[]): number {
    const tupleMap = new Map<number, number>();

    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            const mul = nums[i] * nums[j];
            const cnt = tupleMap.get(mul);
            (cnt) ? tupleMap.set(mul, cnt + 1) : tupleMap.set(mul, 1);
        }
    }

    let answer = 0;
    for (const [mul, cnt] of tupleMap) {
        answer += (cnt >= 2) ? 4 * (cnt - 1) * cnt : 0;
    }

    return answer;
};

console.log(tupleSameProduct([2, 3, 4, 6]));
console.log(tupleSameProduct([1, 2, 4, 5, 10]));
console.log(tupleSameProduct([2, 3, 4, 6, 8, 12]));
console.log(tupleSameProduct([2, 3, 5, 7]));