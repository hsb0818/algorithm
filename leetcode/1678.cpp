/*
[1678. Goal Parser Interpretation]

You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

Given the string command, return the Goal Parser's interpretation of command.

Example 2:

Input: command = "G()()()()(al)"
Output: "Gooooal"
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// TC: O(N)
// SC: O(1)
class Solution {
public:
    string interpret(string command) {
        replaceAll(command, "()", "o");
        replaceAll(command, "(al)", "al");

        return command;
    }

    void replaceAll(string& command, string from, string to) {
        string::size_type n = 0;
                
        while ((n = command.find(from, n)) != string::npos)
        {
            command.replace(n, from.size(), to);
            n += to.size();
        }
    }
};

//void main()
//{
//    Solution s;
//    cout << s.interpret("G()()()()(al)") << endl;
//}