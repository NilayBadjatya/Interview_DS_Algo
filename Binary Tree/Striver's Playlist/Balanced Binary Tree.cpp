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
    bool flag;

    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = 1 + dfs(root->left);
        int right = 1 + dfs(root->right);
        if(abs(left - right) > 1){
            flag = false;
        }
        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        flag = true;
        dfs(root);
        return flag;
    }
};
