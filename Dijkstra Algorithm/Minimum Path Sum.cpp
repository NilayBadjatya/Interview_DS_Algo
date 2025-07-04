typedef pair<int, pair<int, int>> P;
class Solution {
public:

    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dir = {{0, 1}, {1, 0}};
        vector<vector<int>> result(m, vector<int> (n, INT_MAX));
        result[0][0] = grid[0][0];
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({grid[0][0], {0, 0}});
        while(!pq.empty()){
            int sum = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            for(auto& v : dir){
                int x = i + v[0];
                int y = j + v[1];
                if(isValid(x, y, m, n) && result[x][y] > sum + grid[x][y]){
                    result[x][y] = sum + grid[x][y];
                    pq.push({result[x][y], {x, y}});
                }
            }
        }
        return result[m-1][n-1];
    }
};
