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
    int diameterOfBinaryTree(TreeNode* root) {
        int maximum=0;
        CalcDiameter(root, maximum);
        return maximum;
        

        
    }

private:
    int CalcDiameter(TreeNode*root, int&maximum)
    {
        if(root==nullptr)
        {
            return 0;
        }

        int leftdepth= CalcDiameter(root->left,maximum);
        int rightdepth= CalcDiameter(root->right,maximum);

        maximum= max(maximum, leftdepth+rightdepth);

        return max(leftdepth,rightdepth) +1;

    }
};

