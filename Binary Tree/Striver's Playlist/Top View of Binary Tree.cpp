/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            Node* node = q.front().first;
            int dis = q.front().second;
            q.pop();
            if(mp.count(dis) == 0){
                mp[dis] = node->data;
            }
            if(node->left != NULL){
                q.push({node->left, dis-1});
            }
            if(node->right != NULL){
                q.push({node->right, dis+1});
            }
        }
        vector<int> ans;
        for(auto& x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
