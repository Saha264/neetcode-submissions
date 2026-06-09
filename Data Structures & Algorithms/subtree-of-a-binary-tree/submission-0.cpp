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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr)
        {
            return true;
        }
        if(root==nullptr && subRoot!=nullptr)
        {
            return false;
        }

        if(checksame(root, subRoot))
        {
            cout<<"root "<<root->val<<'\n';
            return true;
        }
        else{
            return isSubtree(root->left,subRoot) || isSubtree(root->right, subRoot);
            
        }
        
    }

private:
    bool checksame(TreeNode*p, TreeNode*q)
    {
        if((p==nullptr && q==nullptr))
        {
            return true;
        }
        if(p==nullptr || q==nullptr)
        {
            return false;
        }
        

        bool left=checksame(p->left, q->left);
        bool right=checksame(p->right, q->right);

        if(left && right && ((p==nullptr && q==nullptr) || p->val==q->val))
        {
            return true;
        }
        else{
            return false;
        }
    }
    
    
};
