typedef pair<int, int> P;
class Solution {
public:
    int m, n;
    bool isValid(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    int bfs(vector<vector<int>>& grid, int i, int j){
        int s = 0;
        queue<P> q;
        vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        q.push({i, j}); 
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(visited[i][j]) continue;
                visited[i][j] = true;
                s += grid[i][j];
                for(auto &v : dir){
                    int x = i + v[0];
                    int y = j + v[1];
                    if(isValid(x, y) && grid[x][y] > 0 && !visited[x][y]){
                        q.push({x,y});
                    }
                }
            }
        }
        return s;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int score = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    score =max(score, bfs(grid, i, j));
                }
            }
        }
        return score;
    }
};
