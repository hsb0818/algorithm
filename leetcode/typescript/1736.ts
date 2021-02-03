/*
[1736. Latest Time by Replacing Hidden Digits]
You are given a string time in the form of hh:mm, where some of the digits in the string are hidden (represented by ?).

The valid times are those inclusively between 00:00 and 23:59.

Return the latest valid time you can get from time by replacing the hidden digits.



Example 1:

Input: time = "2?:?0"
Output: "23:50"
Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
Example 2:

Input: time = "0?:3?"
Output: "09:39"
Example 3:

Input: time = "1?:22"
Output: "19:22"


Constraints:

time is in the format hh:mm.
It is guaranteed that you can produce a valid time from the given string.
*/

// ?3:0?

// TC: O(1)
// SC: O(1)
function maximumTime(time: string): string {
    let [h1, h2, m1, m2] = time.replace(/\:/g, '').split('');

    m2 = (m2 === '?') ? '9' : m2;
    m1 = (m1 === '?') ? '5' : m1;

    if (`${h1}${h2}` === '??')
        return `23:${m1}${m2}`;

    h2 = (h2 !== '?') ? h2 : ((h1 !== '2') ? '9' : '3');
    h1 = (h1 !== '?') ? h1 : ((Number(h2) < 4) ? '2' : '1');

    return `${h1}${h2}:${m1}${m2}`;
};

console.log(maximumTime('2?:?0'));
console.log(maximumTime('0?:3?'));
console.log(maximumTime('1?:22'));