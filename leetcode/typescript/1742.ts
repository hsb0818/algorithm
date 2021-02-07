/*
[1742. Maximum Number of Balls in a Box]
You are working in a ball factory where you have n balls numbered from lowLimit up to highLimit inclusive (i.e., n == highLimit - lowLimit + 1), and an infinite number of boxes numbered from 1 to infinity.

Your job at this factory is to put each ball in the box with a number equal to the sum of digits of the ball's number. For example, the ball number 321 will be put in the box number 3 + 2 + 1 = 6 and the ball number 10 will be put in the box number 1 + 0 = 1.

Given two integers lowLimit and highLimit, return the number of balls in the box with the most balls.
*/

// TC: O(N)
// SC: O(N)
function countBalls(lowLimit: number, highLimit: number): number {
    const boxes = new Map<number, number>();
    let maxCnt = 0;
    for (let n = lowLimit; n <= highLimit; n++) {
        const sod = sumOfDigits(n);
        const box = boxes.get(sod);
        boxes.set(sod, box ? box + 1 : 1);

        const cnt = Number(boxes.get(sod));
        maxCnt = Math.max(maxCnt, cnt);
    }

    return maxCnt;
};

function sumOfDigits(n: number) {
    let result = 0;
    while (n > 0) {
        result += n % 10;
        n = Math.floor(n / 10);
    }

    return result;
}

console.log(countBalls(220, 548));