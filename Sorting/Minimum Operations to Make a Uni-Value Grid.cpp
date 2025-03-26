class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int midIdx = (n-1) / 2, ops = 0;
        for(int i = 0; i < n; i++){
            if(i == midIdx) continue;
            int diff = abs(nums[midIdx] - nums[i]);
            if(diff % x != 0){
                return -1;
            }
            ops += diff / x;
        }
        return ops;
    }
};
