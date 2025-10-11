/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int maxSum;
    int solve(Node* root){
        if(!root){
            return 0;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        maxSum = max(maxSum, left + right + root->data);
        maxSum = max(maxSum, max({left, right, 0}) + root->data);
        return max({left, right, 0}) + root->data;
    }
  
    int findMaxSum(Node *root) {
        // code here
        maxSum = INT_MIN;
        maxSum = max(maxSum, solve(root));
        return maxSum;
    }
};
