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
  
    int findNumberOfNodes(Node* root){
        if(!root){
            return 0;
        }
        return 1 + findNumberOfNodes(root->left) + findNumberOfNodes(root->right);
    }
    
    void inorderTraversal(Node* root, int& count, int& median, int medianNode){
        if(!root){
            return;
        }
        inorderTraversal(root->left, count, median, medianNode);
        count++;
        if(count == medianNode){
            median = root->data;
        }
        inorderTraversal(root->right, count, median, medianNode);
    }
  
    int findMedian(Node* root) {
        // Code here
        int nodes = findNumberOfNodes(root);
        // cout << nodes << " ";
        int medianNode;
        if(nodes % 2 == 0){
            medianNode = nodes / 2;
        }else{
            medianNode = (nodes + 1) / 2;
        }
        int median = -1, count = 0;
        inorderTraversal(root, count, median, medianNode);
        return median;
    }
};
