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
 typedef unsigned long long ll;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        ll width = 0;
        while(!q.empty()){
            int size = q.size();
            width = max(width, q.back().second - q.front().second + 1);
            while(size--){
                TreeNode* node = q.front().first;
                ll idx = q.front().second;
                q.pop();
                if(node->left != NULL){
                    q.push({node->left, 2LL * idx + 1});
                }
                if(node->right != NULL){
                    q.push({node->right, 2LL * idx + 2});
                }
            }
        }
        return width;
    }
};
