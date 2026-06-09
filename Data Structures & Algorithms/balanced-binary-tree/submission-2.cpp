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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
        {
            return true;
        }

        

        int leftheight=findheight(root->left);
        int rightheight= findheight(root->right);

        if(abs(leftheight-rightheight)<=1 && isBalanced(root->left) && isBalanced(root->right))
        {
            return true;
        }
        else{
            return false;
        }

        
    }

private:
    int findheight(TreeNode*root)
    {
        if(root==nullptr)
        {
            return 0;
        }

        int leftheight=findheight(root->left);
        int rightheight= findheight(root->right);

        return max(leftheight, rightheight) +1;



    }
};
