#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

//void main() {
//    vector<int> arr = { 6, 2, 5, 1, 7, 4, 8, 3 };
//    vector<int> length(arr.size(), 0);
//    for (int k = 0; k < arr.size(); k++) {
//        length[k] = 1;
//        cout << "---k: " << k << endl;
//        for (int i = 0; i < k; i++) {
//            if (arr[i] < arr[k]) {
//                cout << length[k] << ", " << length[i] + 1 << endl;
//                length[k] = max(length[k], length[i] + 1);
//            }
//        }
//
//        cout << length[k] << endl;
//    }
//}