// C++

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return nullptr;
        }
        if(root == p){
            return root;
        }else if(root == q){
            return root;
        }
        TreeNode* node1 = dfs(root->left, p, q);
        TreeNode* node2 = dfs(root->right, p, q);
        if(node1 && node2){
            return root;
        }else if(node1){
            return node1;
        }else if(node2){
            return node2;
        }
        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};


// JAVA

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {

    private TreeNode dfs(TreeNode root, TreeNode p, TreeNode q){
        if(root == null){
            return null;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode leftA = dfs(root.left, p, q);
        TreeNode rightA = dfs(root.right, p, q);
        if(leftA != null && rightA != null){
            return root;
        }else if(rightA != null){
            return rightA;
        }
        return leftA;
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return dfs(root, p, q);
    }
}
