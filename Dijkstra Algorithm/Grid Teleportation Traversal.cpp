typedef pair<int, pair<int, int>> P;
class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<pair<int, int>>> portals(26);
        vector<bool> isUsed(26, false);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != '.' && matrix[i][j] != '#') {
                    portals[matrix[i][j] - 'A'].push_back({i, j});
                }
            }
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        result[0][0] = 0;
        while (!pq.empty()) {
            int cost = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            int ch = matrix[i][j] - 'A';
            if (matrix[i][j] != '.' && !isUsed[ch]) {
                for (auto& x : portals[ch]) {
                    int x_ = x.first;
                    int y_ = x.second;
                    if (cost < result[x_][y_]) {
                        result[x_][y_] = cost;
                        pq.push({cost, {x_, y_}});
                    }
                }
                isUsed[ch] = true;
            }
            for (auto& v : dir) {
                int x = i + v[0];
                int y = j + v[1];
                if (isValid(x, y, m, n) && matrix[x][y] != '#') {
                    if (cost + 1 < result[x][y]) {
                        result[x][y] = cost + 1;
                        pq.push({cost + 1, {x, y}});
                    }
                }
            }
        }
        return result[m - 1][n - 1] == INT_MAX ? -1 : result[m - 1][n - 1];
    }
};
