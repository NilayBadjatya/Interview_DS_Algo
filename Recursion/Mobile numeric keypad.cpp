class Solution {
  public:
    
    bool isValid(int i, int j){
        return i >= 0 && i < 4 && j >= 0 && j < 3;
    }
    
    long long dp[4][3][16];
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    long long solve(vector<vector<int>>& grid, int i, int j, int len){
        if(len == 0){
            return 1;
        }
        if(dp[i][j][len] != -1){
            return dp[i][j][len];
        }
        long long ans = solve(grid, i, j, len-1);
        for(auto& v : dir){
            int x = i + v[0];
            int y = j + v[1];
            if(isValid(x, y) && grid[x][y] != -1){
                ans += solve(grid, x, y, len-1);
            }
        }
        return dp[i][j][len] = ans;
    }
  
    int getCount(int n) {
        // code here
        vector<vector<int>> grid(4, vector<int> (3, -1));
        int cnt = 1;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                grid[i][j] = cnt++;
            }
        }
        grid[3][1] = 0;
        long long ans = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                if(grid[i][j] != -1){
                    ans += solve(grid, i, j, n-1);
                }
            }
        }
        return ans;
    }
};
