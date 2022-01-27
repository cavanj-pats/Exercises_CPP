//leet 450 Delete Node in BST

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
        TreeNode* temp = root;
        TreeNode* prev = root;
        
        if (root == NULL) return NULL;
        
        if(key != temp->val){
            if (key < temp->val) {
                nodeDeleteHelper(temp->left, prev, key);
            }else
            { nodeDeleteHelper(temp->right, prev, key);}
        } else if (!temp->left && !temp->right){
            //we found the one node it it must be deleted
            return NULL;
        } else if (temp->right){
            temp->right->left = temp->left;
            return temp->right;
             
        }else {
            return temp->left;
        }
        
        return root;
    }
        
    
    void nodeDeleteHelper(TreeNode* node, TreeNode* prev, int key){
        
        if (key == node->val){
            //delte the key
            if (node->right){
                node->right->left = node->left;
                prev->left = node->right;
            }else if(node->left){
                prev->left = node->left;
            }else if (prev->left->val == key){
                prev->left = nullptr;
            }else prev->right = nullptr;
            
        } else if (key < node->val){
            prev = node;
            if (node->left) nodeDeleteHelper(node->left, prev, key);
        }
        else{
            prev = node;
            if(node->right) nodeDeleteHelper(node->right, prev, key);
        }
    }
};