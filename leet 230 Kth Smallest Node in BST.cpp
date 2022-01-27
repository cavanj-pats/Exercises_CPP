//230. Kth Smallest Element in a BST

#include <iostream>


/*
Runtime: 16 ms, faster than 86.86% of C++ online submissions for Kth Smallest Element in a BST.
Memory Usage: 24.5 MB, less than 15.54% of C++ online submissions for Kth Smallest Element in a BST.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* temp = root;
        TreeNode* prev = root;
        int counter = 1;
        vector<int> v;
        nthInOrder(temp, &v);
        return v[k-1];
        
    }
    
    void nthInOrder(TreeNode* node, vector<int>* v){
    
        if(node->left!=nullptr)
            nthInOrder(node->left, v);
        v->push_back(node->val);
        
        if(node->right!=nullptr)
            nthInOrder(node->right, v);
    }
};





