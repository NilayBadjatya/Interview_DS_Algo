class Solution {
public:
    int n;
    int dp[201][201][201];
    int solve(string& s, int i, int j, int k) {
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
            return 2 + solve(s, i+1, j-1, k);
        }
        int cost = min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]));
        int take = 0, skip = 0;
        if(cost <= k){
            take = 2 + solve(s, i+1, j-1, k - cost);
        }
        skip = max(solve(s, i+1, j, k), solve(s, i, j-1, k));
        return dp[i][j][k] = max(take, skip);
    }

    int longestPalindromicSubsequence(string s, int k) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, n-1, k);
    }
};
