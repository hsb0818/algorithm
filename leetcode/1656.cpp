#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

// SC: O(N)
class OrderedStream {
    vector<string> stream;
    int cur = 1;
public:
    OrderedStream(int n) {
        stream.clear();
        stream.resize(n + 1);
        cur = 1;
    }

    // TC: 
    // 최선: O(1)
    // 최악: O(N) -> 마지막으로 1번째가 채워질 때
    vector<string> insert(int id, string value) {
        stream[id] = value;
        if (cur != id) {
            return {};
        }

        int start = cur;
        int end = cur;
        for (; end < stream.size(); end++, cur++) {
            if (stream[end].empty())
                break;
        }

        return vector<string>(stream.begin() + start, stream.begin() + end);
    }
};


/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */