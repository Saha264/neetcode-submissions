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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serhelper(root,ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return dehelper(ss);
    }

private:
    void serhelper(TreeNode* root, stringstream&ss)
    {
        if(!root){
            ss<<"# ";
            return;
        }
        ss<<root->val<< " ";
        serhelper(root->left,ss);
        serhelper(root->right,ss);
    }

    TreeNode*dehelper(stringstream&ss)
    {
        string token;

        ss>> token;

        if(token=="#")
        {
            return nullptr;
        }

        TreeNode*root= new TreeNode(stoi(token));
        root->left=dehelper(ss);
        root->right=dehelper(ss);

        return root;

    }
};
