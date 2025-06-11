class Solution {
public:

    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited, int m, int n){
        visited[i][j] = true;
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for(auto& v : dir){
            int x = i + v[0];
            int y = j + v[1];
            if(isValid(x, y, m, n) && grid[x][y] == '1' && !visited[x][y]){
                dfs(grid, x, y, visited, m, n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int islands = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, i, j, visited, m, n);
                    islands++;
                }
            }
        }

        return islands;
    }
};
