class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int minMoves(vector<string>& grid, int energy) {
        int m = grid.size(), n = grid[0].size(), litter = 0;
        pair<int, int> start;
        map<pair<int, int>, int> lit_id;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    start = {i, j};
                } else if (grid[i][j] == 'L') {
                    lit_id[{i, j}] = litter++;
                }
            }
        }

        vector<vector<int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

        int full_mask = (1 << litter) - 1;

        bool vis[20][20][1 << 10][51];
        memset(vis, false, sizeof(vis));

        struct State{
            int x, y, mask, e, d;
        };

        vis[start.first][start.second][0][energy] = true;

        queue<State> q;
        q.push({start.first, start.second, 0, energy, 0});

        while(!q.empty()){
            State s = q.front();
            q.pop();

            int i = s.x;
            int j = s.y;
            int mask = s.mask;
            int e = s.e;
            int dis = s.d;

            if(mask == full_mask){
                return dis;
            }

            if(e == 0) continue;

            for(auto& d : dir){
                int x = i + d[0];
                int y = j + d[1];
                int new_mask = mask;
                int new_energy = e-1;
                if(isValid(x, y, m, n) && grid[x][y] != 'X'){
                    if(grid[x][y] == 'R'){
                        new_energy = energy;
                    }
                    if(grid[x][y] == 'L'){
                        new_mask |= (1 << lit_id[{x, y}]);
                    }
                    if(!vis[x][y][new_mask][new_energy]){
                        vis[x][y][new_mask][new_energy] = true;
                        q.push({x, y, new_mask, new_energy, dis+1});
                    }
                }
            }
        }
        return -1;
    }
};
