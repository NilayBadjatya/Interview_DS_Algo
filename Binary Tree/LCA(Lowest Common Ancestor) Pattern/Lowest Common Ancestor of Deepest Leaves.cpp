//C++
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

    pair<TreeNode*, int> dfs(TreeNode* root){
        if(!root){
            return {nullptr, 0};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if(left.second > right.second){
            return {left.first, left.second + 1};
        }else if(right.second > left.second){
            return {right.first, right.second + 1};
        }
        return {root, left.second+1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};

//JAVA
class Solution {
    class Pair {
        TreeNode node;
        int depth;

        Pair(TreeNode node, int depth) {
            this.node = node;
            this.depth = depth;
        }
    }

    private Pair dfs(TreeNode root) {
        if (root == null) {
            return new Pair(null, 0);
        }

        Pair left = dfs(root.left);
        Pair right = dfs(root.right);

        if (left.depth > right.depth) {
            return new Pair(left.node, left.depth + 1);
        } else if (right.depth > left.depth) {
            return new Pair(right.node, right.depth + 1);
        } else {
            return new Pair(root, left.depth + 1);
        }
    }

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return dfs(root).node;
    }
}
