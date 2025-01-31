class Solution {
public:
    bool isValid(int x, int y, int n) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }
    int bfs(vector<vector<int>>& grid, int i, int j, int n,
                 vector<vector<bool>>& visited, int id) {
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> pq;
        pq.push({i, j});
        int islands = 0;
        while (!pq.empty()) {
            int x = pq.front().first;
            int y = pq.front().second;
            pq.pop();
            if (visited[x][y])
                continue;
            visited[x][y] = true;
            grid[x][y] = id;
            islands++;
            for (auto& v : dir) {
                int x_ = x + v[0];
                int y_ = y + v[1];
                if (isValid(x_, y_, n) && !visited[x_][y_] &&
                    grid[x_][y_] == 1) {
                    pq.push({x_, y_});
                }
            }
        }
        return islands;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        unordered_map<int, int> mp;
        int uniqId = 2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    mp[uniqId] = bfs(grid, i, j, n, visited, uniqId);
                    // cout << mp[uniqId] << " ";
                    uniqId++;
                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int res = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    int temp = 1;
                    unordered_set<int> st;
                    for(auto &v : dir){
                        int x = i + v[0];
                        int y = j + v[1];
                        if(isValid(x, y, n) && grid[x][y] > 1){
                            st.insert(grid[x][y]);
                        }
                    }
                    for(auto& v : st){
                        temp += mp[v];
                    }
                    res = max(res, temp);
                }
            }
        }
        return res == INT_MIN ? n*n : res;
    }
};
