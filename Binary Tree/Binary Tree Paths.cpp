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

    void dfs(TreeNode* root, vector<string>& s, string path){
        path += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            s.push_back(path);
            return;
        }
        path += "->";
        if(root->left)
        dfs(root->left, s, path);
        if(root->right)
        dfs(root->right, s, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> s;
        dfs(root, s, "");
        return s;
    }
};
