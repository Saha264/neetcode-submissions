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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> check;
        int n= inorder.size();
        for(int i=0;i<n;i++)
        {
            check[inorder[i]]=i;

        }

        
        int counter=0;

        return build(preorder, inorder, 0, n - 1, counter, check);

    }

private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l,int r,int& counter, unordered_map<int,int>& check)
    {
        if(l>r)
        {
            return nullptr; 
        }
        int rootValue = preorder[counter];
        TreeNode* root = new TreeNode(rootValue);
        
       
        counter++;

        int mid = check[rootValue];

        root->left = build(preorder, inorder, l, mid - 1, counter, check);
        root->right = build(preorder, inorder, mid + 1, r, counter, check);

     
        return root;

        

        



    }
};
