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
    int goodNodes(TreeNode* root) {
        int count=0;
        int rootval=root->val;
        int maxval=rootval;

        find(root,count,rootval,maxval);
        return count;


    }
private:
    void find(TreeNode*root, int&count,int rootval,int maxval)
    {
        if(root==nullptr)
        {
            return;
        }

        
        if(root->val>=maxval)
        {
            maxval=root->val;
            count++;
        }
        
        find(root->left,count,rootval,maxval);
        find(root->right,count,rootval,maxval);
        


    }
};
