//Time Complexity - O(N^2)
//Space Complexity - O(N^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int a, b;
        vector<bool> vis(n*n + 1, false);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(vis[grid[i][j]]){
                    a = grid[i][j];
                }
                vis[grid[i][j]] = true;
            }
        }
        for(int i = 1; i <= n*n; i++){
            if(!vis[i]){
                b = i;
                break;
            }
        }
        return {a, b};
    }
};
