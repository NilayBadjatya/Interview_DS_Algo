typedef pair<TreeNode*, int> P;
class FindElements {
public:
    unordered_set<int> st;
    FindElements(TreeNode* root) {
        queue<P> q;
        q.push({root, 0});
        int val = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front().first;
                int value = q.front().second;
                q.pop();
                st.insert(value);
                node->val = value;
                if (node->left) {
                    q.push({node->left, value * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, value * 2 + 2});
                }
            }
        }
    }

    bool find(int target) { return st.count(target); }
};
