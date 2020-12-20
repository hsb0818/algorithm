/*
[160. Intersection of Two Linked Lists]
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// TC: O(N)
// SC: O(N)
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_map<ListNode*, int> hashTable;

        for (ListNode* node = headA; node != nullptr; node = node->next)
            hashTable.insert(make_pair(node, node->val));

        for (ListNode* node = headB; node != nullptr; node = node->next) {
            unordered_map<ListNode*, int>::iterator elem = hashTable.find(node);

            if (elem != hashTable.end()) {
                return node;
            }
        }

        return nullptr;
    }
};