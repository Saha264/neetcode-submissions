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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==nullptr)
        {
            return result;
        }
      
        queue<TreeNode*> level;
        level.push(root);
        
        while(!level.empty())
        {
            int size=level.size();
            TreeNode*temp= level.front();

            for(int i=0;i<size-1;i++)
            {
                
                TreeNode*temp= level.front();
                level.pop();
                

                if(temp->left)
                {
                    level.push(temp->left);
                }
                if(temp->right)
                {
                    level.push(temp->right);
                }
            }
            temp= level.front();
             if(temp->left)
            {
                level.push(temp->left);
            }
            if(temp->right)
            {
                level.push(temp->right);
            }
            

            result.push_back(temp->val);
            level.pop();

            

        }
        return result;
    }
};
