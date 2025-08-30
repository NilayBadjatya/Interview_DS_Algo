/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    
    bool solve(Node* root, int minVal, int maxVal){
        if(!root) return true;
        if(root->data < minVal || root->data > maxVal){
            return false;
        }
        bool left = solve(root->left, minVal, root->data-1);
        bool right = solve(root->right, root->data+1, maxVal);
        if(!left || !right){
            return false;
        }
        return true;
    }
    
    bool isBST(Node* root) {
        // Your code here
        return solve(root, INT_MIN, INT_MAX);
    }
};
