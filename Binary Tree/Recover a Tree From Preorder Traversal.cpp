/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        unordered_map<int, TreeNode*> mp;
        int i = 0;
        while(i < s.size()){
            int d = 0; 
            // Calculating the depth of the current node.
            while(i < s.size() && s[i] == '-'){
                d++;
                i++;
            }
            // Calculating the value of the current node.
            string valString = "";
            while(i < s.size() && isdigit(s[i])){
                valString += s[i];
                i++;
            }
            int val = stoi(valString);
            // Creating new node.
            TreeNode* node = new TreeNode(val);
            if(d > 0){// Assigning the newly formed node to its parent, if it is other than root node.
                TreeNode* parent = mp[d-1];
                if(parent->left == NULL){
                    parent->left = node;
                }else{
                    parent->right = node;
                }
            }
            mp[d] = node;// Updating the current depth with the current node.
        }
        return mp[0];
    }
};
