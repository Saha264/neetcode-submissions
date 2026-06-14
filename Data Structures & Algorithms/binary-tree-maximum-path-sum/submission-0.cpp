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
    int maxPathSum(TreeNode* root) {
        int maxval= -1000;

        findsum(root,maxval);
        return maxval;
    }

private:
    int findsum(TreeNode*root, int& maxval)
    {
        if(root==nullptr)
        {
            return 0;
        }
        

        int left=max(findsum(root->left,maxval),0);
        int right=max(findsum(root->right,maxval),0);

        int both= root->val+ left+right;

        maxval= max(maxval,both);

        return root->val+ max(left,right);
    }
};
