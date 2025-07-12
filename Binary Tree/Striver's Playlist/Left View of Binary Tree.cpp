/* A binary tree node

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
  
    void bfs(Node* root, vector<int>& ans){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            bool first = false;
            while(size--){
                Node* node = q.front();
                q.pop();
                if(!first){
                    ans.push_back(node->data);
                    first = true;
                }
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
        }
    }
  
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL){
            return {};
        }
        bfs(root, ans);
        return ans;
    }
};
