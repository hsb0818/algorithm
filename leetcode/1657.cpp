#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std; 

// TC: O(NLog(N)) : O(1) * 2 + O(N) * 2 + O(2NLog(N))
// SC: O(1)

/*
문제설명
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
    For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
    For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

Operation 1은 신경쓰지말고 Operation 2를 보면 문자를 이미 존재하는 다른 문자로 변경이 가능하므로
문자가 무엇이든 전체적으로 Frequency들이 맞아 떨어져야 한다.
그러니 Frequency를 정렬해서 같은지만 비교하면 된다.
*/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int freqs1[26] = { 0, }, freqs2[26] = { 0, };
        setFreqsInto(freqs1, word1);
        setFreqsInto(freqs2, word2);

        // O(1)
        for (int i = 0; i < 26; i++) {
            bool exist1 = freqs1[i] != 0;
            bool exist2 = freqs2[i] != 0;

            if (exist1 != exist2) {
                return false;
            }
        }

        // O(NLog(N))
        sort(freqs1, freqs1 + 26);
        sort(freqs2, freqs2 + 26);

        for (int i = 0; i < 26; i++) {
            if (freqs1[i] != freqs2[i]) {
                return false;
            }
        }

        return true;
    }

    // O(N)
    void setFreqsInto(int freqs[], string& word) {
        for (int i = 0; i < word.length(); i++) {
            freqs[word[i] - 'a']++;
        }
    }
};