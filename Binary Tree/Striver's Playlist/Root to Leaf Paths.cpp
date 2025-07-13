/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    void solve(Node* root, vector<int> temp, vector<vector<int>>& list){
        if(root->left == NULL && root->right == NULL){
            temp.push_back(root->data);
            list.push_back(temp);
            return;
        }
        temp.push_back(root->data);
        if(root->left != NULL){
            solve(root->left, temp, list);
        }
        if(root->right != NULL){
            solve(root->right, temp, list);
        }
        // temp.pop_back();
    }
  
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int> temp;
        vector<vector<int>> list;
        solve(root, temp, list);
        return list;
    }
};
