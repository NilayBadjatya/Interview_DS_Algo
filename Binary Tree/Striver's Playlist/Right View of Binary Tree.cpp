/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution {
  public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        // Your Code here
        vector<int> ans;
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
                if(node->right != NULL){
                    q.push(node->right);
                }
                if(node->left != NULL){
                    q.push(node->left);
                }
            }
        }
        return ans;
    }
};
