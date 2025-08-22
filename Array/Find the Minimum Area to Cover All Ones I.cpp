class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> nums;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    nums.push_back({i, j});
                }
            }
        }
        vector<int> mini(2, INT_MAX), maxi(2, INT_MIN);
        for(int i = 0; i < nums.size(); i++){
            mini[0] = min(mini[0], nums[i][0]);
            mini[1] = min(mini[1], nums[i][1]);

            maxi[0] = max(maxi[0], nums[i][0]);
            maxi[1] = max(maxi[1], nums[i][1]);
        }

        int area = (maxi[0] - mini[0] + 1) * (maxi[1] - mini[1] + 1);
        return area;
    }
};
