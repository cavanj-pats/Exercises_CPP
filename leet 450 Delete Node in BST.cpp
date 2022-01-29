//leet 450 Delete Node in BST

//i gave up and used leetcode discussion code

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* iter = root, *par = nullptr;
		// search for key node & keep a pointer to current node's parent
        while(iter && iter -> val != key) {                              
            par = iter;
            if(iter -> val < key) iter = iter -> right;
            else iter = iter -> left;
        }
        if(!iter) return root;                                           // node not found  => Case:1
        // iter is the node to be deleted
        
        // node found with less than two children  => Case-2/3/4 combined
        if(!iter -> left or !iter -> right) {
            auto child = iter -> left ? iter -> left : iter -> right;    // find child node of iter if it exists
            if(!par) root = child;                                       // iter is root node. Update root as child of iter
            else if(par -> left == iter) par -> left = child;            // iter is left child. Update its parent's left pointer as iter's child
            else par -> right = child;                                   // Else update parent's right pointer as iter's child
        }
        // node found with both children => Case-5
        else {
            auto cur = iter;                                              // cur maintains a reference to the node to be deleted
            par = iter, iter = iter -> right;                             // go to right subtree 
            while(iter -> left) par = iter, iter = iter -> left;          // and find smallest node in that right subtree
            cur -> val = iter -> val;                                     // delete by replacing with smallest node found
			// smallest node replaced from right subtree may have a right child. 
			// So update that node's parent to hold the right child
            if(par -> left == iter) par -> left = iter -> right;          
            else par -> right = iter -> right;
        }
		// dont show the interviewer that you are a leaker :)
        delete iter;        // free the memory		
        return root;
    }
};