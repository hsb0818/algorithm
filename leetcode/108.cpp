/**
[108. Convert Sorted Array to Binary Search Tree]

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 * Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// TC: ÃÖ¾ÇÀÇ °æ¿ì O(N)
// SC: O(N)
class Solution {
private:
    class BinaryTree
    {
    private:
        TreeNode* root = nullptr;
    public:
        BinaryTree(vector<int>& sortedVector)
        {
            root = build(sortedVector, 0, sortedVector.size());
        }

        TreeNode* get() { return this->root; }
    private:
        TreeNode* build(vector<int>& nums, int left, int right)
        {   
            if (left >= right) 
                return nullptr;

            int mid = (left + right) / 2;
            TreeNode* node = new TreeNode(nums[mid], build(nums, left, mid), build(nums, mid + 1, right));
            
            return node;
        }

        // orderType
        // 0 --> preorder
        // 1 --> inorder
        // 2 --> postorder
        void print(TreeNode* node, int orderType = 0)
        {
            if (node == nullptr)
                return;

            if (orderType == 0)
            {
                print(node->left, orderType);
                cout << node->val<<", ";
                print(node->right, orderType);
            }
            else if (orderType == 1)
            {
                cout << "inorder: "<<node->val << ", ";
                print(node->left, orderType);
                print(node->right, orderType);
            }
            else if (orderType == 2)
            {
                print(node->left, orderType);
                print(node->right, orderType);
                cout << node->val << ", ";
            }
        }
    public:
        void print(int orderType)
        {
            print(root, orderType);
        }
    };

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        BinaryTree tree(nums);

        //tree.print(1);
        return tree.get();
    }
};

void main()
{
    vector<int> input = { -10,-3,0,5,9 };
    Solution s;
    s.sortedArrayToBST(input);
}