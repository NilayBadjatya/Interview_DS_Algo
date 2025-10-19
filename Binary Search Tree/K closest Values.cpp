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
  
    void solve(Node* root, int target, vector<vector<int>>& nums){
        if(!root){
            return;
        }
        nums.push_back({abs(root->data - target), root->data});
        solve(root->left, target, nums);
        solve(root->right, target, nums);
    }
  
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        vector<vector<int>> nums;
        solve(root, target, nums);
        sort(nums.begin(), nums.end());
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(nums[i][1]);
        }
        return res;
    }
};
