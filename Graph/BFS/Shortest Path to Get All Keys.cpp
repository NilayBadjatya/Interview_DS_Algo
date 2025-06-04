class Solution {
public:

    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        pair<int, int> start;
        map<char, int> keys;
        int countKey = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '@'){
                    start.first = i;
                    start.second = j;
                }else if(islower(grid[i][j])){
                    keys[grid[i][j]] = countKey;
                    countKey++;
                }
            }
        }
        struct State{
            int d, x, y, mask;
        };
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int full_mask = (1 << countKey) - 1;
        bool vis[30][30][1 << 6];
        vis[start.first][start.second][0] = true;
        queue<State> q;
        q.push({0, start.first, start.second, 0});
        while(!q.empty()){
            auto [d, x, y, mask] = q.front();
            q.pop();
            if(mask == full_mask){
                return d;
            }
            for(auto& di : dir){
                int i = x + di[0];
                int j = y + di[1];
                int new_mask = mask;
                if(isValid(i, j, m, n) && grid[i][j] != '#'){
                    if(isupper(grid[i][j])){
                        if((new_mask & (1 << keys[tolower(grid[i][j])])) == 0){
                            continue;
                        }
                    }
                    if(islower(grid[i][j])){
                        new_mask |= (1 << (keys[grid[i][j]]));
                    }
                    if(!vis[i][j][new_mask]){
                        vis[i][j][new_mask] = true;
                        q.push({d+1, i, j, new_mask});
                    }
                }
            }
        }
        return -1;
    }
};
