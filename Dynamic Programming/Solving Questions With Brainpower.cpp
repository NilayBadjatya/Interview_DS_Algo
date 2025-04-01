class Solution {
public:
    long long dp[100001];
    long long solve(vector<vector<int>>& nums, int i){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        long long take = nums[i][0] + solve(nums, nums[i][1] + i + 1);
        long long skip = solve(nums, i+1);
        return dp[i] = max(take, skip);
    }

    long long mostPoints(vector<vector<int>>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};
