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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr)
        {
            return result;
        }
      
        queue<TreeNode*> level;
        level.push(root);
        
        while(!level.empty())
        {
            int size=level.size();
            vector<int>current;

            for(int i=0;i<size;i++)
            {
                
                TreeNode*temp= level.front();
                level.pop();
                current.push_back(temp->val);

                if(temp->left)
                {
                    level.push(temp->left);
                }
                if(temp->right)
                {
                    level.push(temp->right);
                }
            }
            result.push_back(current);

            

        }
        return result;





        


    }
private:
    vector<vector<int>> setlevel(TreeNode*root, vector<vector<int>> result,queue<int> level)
    {

       
        
    }
};
