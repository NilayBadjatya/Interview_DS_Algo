class Solution {
  public:
    int m, n;
    int solve(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp){
        if(i < 0 || j < 0 || i == m || j == n) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int rdiag = mat[i][j] + solve(mat, i-1, j+1, dp);
        int right = mat[i][j] + solve(mat, i, j+1, dp);
        int bdiag = mat[i][j] + solve(mat, i+1, j+1, dp);
        return dp[i][j] = max({rdiag, right, bdiag});
    }
  
    int maxGold(vector<vector<int>>& mat) {
        // code here
        m = mat.size();
        n = mat[0].size();
        
        int ans = INT_MIN;
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        for(int i = 0; i < m; i++){
            ans = max(ans, solve(mat, i, 0, dp));
        }
        return ans;
    }
};
