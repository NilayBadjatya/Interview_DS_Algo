class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }
        if(i == grid.size() || j == grid[0].size()){
            return 1e9;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = grid[i][j] + solve(grid, i, j+1, dp);
        int down = grid[i][j] + solve(grid, i+1, j, dp);
        return dp[i][j] = min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return solve(grid, 0, 0, dp);
    }
};
