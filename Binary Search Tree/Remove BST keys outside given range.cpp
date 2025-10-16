/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    Node* solve(Node* root, int l, int r){
        if(!root){
            return nullptr;
        }
        if(root->data > r){
            return solve(root->left, l, r);
        }
        if(root->data < l){
            return solve(root->right, l, r);
        }
        
        Node* right = solve(root->right, l, r);
        Node* left = solve(root->left, l, r);
        
        root->left = left;
        root->right = right;
        return root;
    }
  
    Node* removekeys(Node* root, int l, int r) {
        // code here
        return solve(root, l, r);
    }
};
