

#include <iostream>
#include <vector>


using namespace std;


//* Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left; 
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //if the left side is below the right side, need to include those nodes 
        //that are visible from the right side.
        
        vector<int> ans;
        vector<int> val;
        vector<int> height;

        TreeNode* temp = root;
        int lh, rh, h = 0;
        lh = getHeight(temp->left);
        rh = getHeight(temp->right);

        mapNodeValAndHeightToVectors(val, height, root, h);

        if(!temp) return ans;
        ans.push_back(temp->val);
        
        while(1){
            if(temp->right){
                temp = temp->right;
            } else if (temp->left){
                temp = temp->left;
            } else{
                break;
            }
            
           ans.push_back(temp->val);
        }
        return ans;
    }
    
private:
    int getHeight(TreeNode* Node){
        int max_height=0;

        if (Node==NULL){
            return 0;
        }
        else
        {
            /* compute the height of each subtree */
            int lHeight = getHeight(Node->left);
            int rHeight = getHeight(Node->right);

            if(lHeight >= rHeight)
                max_height = lHeight;
            else   
                max_height = rHeight;


            return max_height+1;;
        }
    }



  
    void mapNodeValAndHeightToVectors(vector<int> &val, vector<int> &height, TreeNode* root, int h){
        
        if (root == nullptr){
            return;
        }else{
            //inorder traversal is required
            mapNodeValAndHeightToVectors(val, height, root->left, h++);
            val.push_back(root->val);
            val.push_back(h);
            mapNodeValAndHeightToVectors(val, height, root->right, h++);

        }

    }


};


int main(){
    TreeNode* n = new TreeNode(1);
    n->left = new TreeNode(2);
    n->left->right = new TreeNode(5);
    n->right = new TreeNode(3);
    n->right->right = new TreeNode(4);
    n->left->right->right = new TreeNode(6);

    Solution sol;
    vector<int> ans;

    ans = sol.rightSideView(n);

    cout << "done" << endl;

    return 0;
}