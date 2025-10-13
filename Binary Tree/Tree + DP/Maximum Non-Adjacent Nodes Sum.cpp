/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    unordered_map<Node*, int> mp;
    int solve(Node* root){
        if(!root){
            return 0;
        }
        if(mp.count(root) != 0){
            return mp[root];
        }
        int take = 0;
        if(root->left){
            take += solve(root->left->left);
            take += solve(root->left->right);
        }
        if(root->right){
            take += solve(root->right->right);
            take += solve(root->right->left);
        }
        take += root->data;
        
        int skip = solve(root->left);
        skip += solve(root->right);
        
        return mp[root] = max(take, skip);
    }
  
    int getMaxSum(Node *root) {
        // code here
        return solve(root);
    }
};
