class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ing,
                                  vector<string>& supplies) {
        unordered_set<string> st;
        for (auto& s : supplies) {
            st.insert(s);
        }
        int n = recipes.size();
        vector<string> res;
        vector<bool> cooked(n, false);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if(cooked[k]) continue;
                bool present = true;
                for (int j = 0; j < ing[k].size(); j++) {
                    if (st.count(ing[k][j]) == 0) {
                        present = false;
                        break;
                    }
                }
                if (present) {
                    st.insert(recipes[k]);
                    res.push_back(recipes[k]);
                    cooked[k] = true;
                }
            }
        }
        return res;
    }
};
