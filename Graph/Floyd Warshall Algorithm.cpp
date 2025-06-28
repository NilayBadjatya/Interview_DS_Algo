// Multi Source Shortest Path Algorithm
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &grid) {
        // Code Here
        int n = grid.size();
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][via] == 1e8 || grid[via][j] == 1e8) continue;
                    grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                }
            }
        }
        
        // To Detect Negative Cycle, we can check the diagonal elements i.e. 
        // if any of the diagonal element < 0 the negative cycle exist
    }
};
