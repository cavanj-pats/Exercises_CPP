



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //if the left side is below the right side, need to include those nodes 
        //that are visible from the right side.
        
        vector<int> ans;
        TreeNode* temp = root;
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
};