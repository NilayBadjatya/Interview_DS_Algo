class Solution {
public:
    int dp[202][202][202];
    int solve(string &s, int i, int j, int k){
        if(i == j){
            return 1;
        }
        if(i > j){
            return 0;
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        if(s[i] == s[j]){
            return dp[i][j][k] = 2 + solve(s, i+1, j-1, k);
        }
        int x = abs(s[i] - s[j]);
        x = min(x, 26 - x);
        int c = 0;
        if(x <= k){
            c = 2 + solve(s, i+1, j-1, k - x);
        }
        return dp[i][j][k] = max({c, solve(s, i+1, j, k), solve(s, i, j-1, k)});
    }

    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, n-1, k);
    }
};
