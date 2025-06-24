typedef pair<int, int> P;
class Solution {
public:

    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<P> q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto& v : dir){
                    int x = i + v[0];
                    int y = j + v[1];
                    if(isValid(x, y, m, n) && grid[x][y] == 1){
                        q.push({x, y});
                        grid[x][y] = 2;
                        flag = true;
                    }
                }
            }
            if(flag)
                time++;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return time;
    }
};
