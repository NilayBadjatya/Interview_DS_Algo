/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unordered_map<int, multiset<int>> levelmap;
            while (size--) {
                TreeNode* node = q.front().first;
                int val = q.front().second;
                levelmap[val].insert(node->val);
                q.pop();
                if (node->left != NULL) {
                    q.push({node->left, val - 1});
                }
                if (node->right != NULL) {
                    q.push({node->right, val + 1});
                }
            }
            for(auto& x : levelmap){
                int val = x.first;
                for(auto& num : x.second){
                    mp[val].push_back(num);
                }
            }
        }

        vector<vector<int>> ans;
        for (auto& x : mp) {
            vector<int> temp;
            for (auto& val : x.second) {
                temp.push_back(val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
