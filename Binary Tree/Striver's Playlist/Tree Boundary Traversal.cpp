/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  vector<int> ans;
  
    void dfs1(Node* root, set<Node*>& st){
        if(!root){
            return;
        }
        if(st.count(root) == 0){
            ans.push_back(root->data);
            st.insert(root);
        }
        dfs1(root->left, st);
        if(root->left == NULL){
            dfs1(root->right, st);
        }
    }
    
    void dfs3(Node* root, set<Node*>& st){
        if(!root){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(st.count(root) == 0){
                ans.push_back(root->data);
                st.insert(root);
            }
            return;
        }
        dfs3(root->left, st);
        dfs3(root->right, st);
    }
    
    void dfs2(Node* root, set<Node*>& st){
        if(!root){
            return;
        }
        dfs2(root->right, st);
        if(root->right == NULL){
            dfs2(root->left, st);
        }
        if(st.count(root) == 0){
            ans.push_back(root->data);
            st.insert(root);
        }
    }
    
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        set<Node*> st;
        ans.push_back(root->data);
        st.insert(root);
        dfs1(root->left, st);
        dfs3(root, st);
        dfs2(root->right, st);
        return ans;
    }
};
