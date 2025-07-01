class Solution {
public:
    int dp[302][302];
    int solve(vector<int>& nums, int i, int j){
        // if(i == j){
        //     return nums[i];
        // }
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int cost = 0;
        for(int k = i; k <= j; k++){
            int temp = nums[i-1] * nums[k] * nums[j+1];
            cost = max(cost, temp + solve(nums, i, k-1) + solve(nums, k+1, j));
        }
        return dp[i][j] = cost;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp, -1, sizeof(dp));
        return solve(nums, 1, n);
    }
};
