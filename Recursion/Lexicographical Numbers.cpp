class Solution {
public:

    void dfs(string num, vector<int>& ans, int n){
        if(stoi(num) > n) return;
        ans.push_back(stoi(num));
        for(int i = 0; i <= 9; i++){
            string t = num;
            t += (i + '0');
            dfs(t, ans, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i <= min(n, 9); i++){
            dfs(to_string(i), ans, n);
        }
        return ans;
    }
};
