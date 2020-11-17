#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // TC: O(n^2)
    // SC: O(1)
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        for (int i = 0; i < arr.size();) {
            vector<int> carr = findCarr(arr[i], pieces);

            if (carr.empty()) {
                return false;
            }

            if (!equal(arr.begin() + i, arr.begin() + i + carr.size(), carr.begin())) {
                return false;
            }

            i += carr.size();
        }

        return true;
    }

    vector<int> findCarr(int e, vector<vector<int>>& pieces) {
        for (int i = 0; i < pieces.size(); i++) {
            if (pieces[i][0] == e) {
                return pieces[i];
            }
        }

        return vector<int>();
    }
};

//int main()
//{
//    Solution s;
//    vector<vector<int>> pieces;
//    pieces.push_back({ 78 });
//    pieces.push_back({ 4, 64 });
//    pieces.push_back({ 91 });
//
//    vector<int> arr = { 91, 4, 64, 78 };
//
//    cout << (s.canFormArray(arr, pieces) ? "true" : "false") << endl;
//}