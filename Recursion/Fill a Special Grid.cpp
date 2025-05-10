class Solution {
public:
    int val = 0;
    void solve(vector<vector<int>>& grid, int row, int col, int n){
        if(n == 1){
            grid[row][col] = val++;
            return;
        }
        n = n/2;
        solve(grid, row, col + n, n);
        solve(grid, row+n, col+n, n);
        solve(grid, row+n, col, n);
        solve(grid, row, col, n);
    }

    vector<vector<int>> specialGrid(int N) {
        int n = 1 << N;
        vector<vector<int>> grid(n, vector<int> (n));
        solve(grid, 0, 0, n);
        return grid;
    }
};
