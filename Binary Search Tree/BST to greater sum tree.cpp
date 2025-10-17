/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
  
    void solve(Node* root, vector<int>& val){
        if(!root){
            return;
        }
        val.push_back(root->data);
        solve(root->left, val);
        solve(root->right, val);
    }
    
    void transform(Node* root, map<int, int>& mp){
        if(!root){
            return;
        }
        root->data = mp[root->data];
        transform(root->left, mp);
        transform(root->right, mp);
    }
  
    void transformTree(Node *root) {
        // code here
        vector<int> val;
        solve(root, val);
        sort(val.begin(), val.end());
        map<int, int> mp;
        int n = val.size();
        vector<int> prefix(n, 0);
        prefix[n-1] = 0;
        mp[val[n-1]] = prefix[n-1];
        for(int i = n - 2; i >= 0; i--){
            prefix[i] = prefix[i+1] + val[i+1];
            mp[val[i]] = prefix[i];
        }
        transform(root, mp);
    }
};
