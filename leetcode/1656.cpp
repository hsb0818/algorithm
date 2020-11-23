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
    // �ּ�: O(1)
    // �־�: O(N) -> ���������� 1��°�� ä���� ��
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