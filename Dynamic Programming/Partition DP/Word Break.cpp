class Solution {
public:

    bool solve(string& s, int i, int j, unordered_set<string>& st, vector<vector<int>>& dp){
        if(i > j){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j] == 1;
        }
        bool ans  = false;
        for(int k = i; k <= j; k++){
            string t = s.substr(i, k - i + 1);
            if(st.count(t) != 0 && solve(s, k+1, j, st, dp)){
                ans = true;
                break;
            }
        }
        return dp[i][j] = ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(s, 0, s.size()-1, st, dp);
    }
};
