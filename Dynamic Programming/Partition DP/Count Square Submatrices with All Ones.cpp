class Solution {
public:

    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = solve(grid, i, j+1, dp);
        int down = solve(grid, i+1, j, dp);
        int diag = solve(grid, i+1, j+1, dp);
        return dp[i][j] = 1 + min({right, down, diag});
    }

    int countSquares(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    ans += solve(grid, i, j, dp);
                }
            }
        }
        return ans;
    }
};
