/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
        queue<Node*> q;
        vector<int> res;
        int level = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                Node* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                temp.push_back(node->data);
            }
            if(level % 2 != 0){
                for(int i = temp.size() - 1; i >= 0; i--){
                    res.push_back(temp[i]);
                }
            }else{
                for(int i = 0; i < temp.size(); i++){
                    res.push_back(temp[i]);
                }
            }
            level++;
        }
        return res;
    }
};
