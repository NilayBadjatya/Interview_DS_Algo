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

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end, int& idx){
        if(start > end){
            return NULL;
        }
        int rootVal = postorder[idx];
        // cout << rootVal << " ";
        TreeNode* root = new TreeNode(rootVal);
        int i = 0;
        for(int j = 0; j < inorder.size(); j++){
            if(inorder[j] == rootVal){
                i = j;
                break;
            }
        }
        idx--;
        root->right = solve(inorder, postorder, i+1, end, idx);
        root->left = solve(inorder, postorder, start, i-1, idx);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int idx = n-1;
        return solve(inorder, postorder, 0, n-1, idx);
    }
};
