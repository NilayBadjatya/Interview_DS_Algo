class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(vector<int>& nums, int prev, int idx){
        if(prev < idx && idx == n-1){
            return max(nums[idx], nums[prev]);
        }
        if(idx == n){
            return nums[prev];
        }
        if(dp[prev][idx] != -1){
            return dp[prev][idx];
        }
        int cost = INT_MAX;
        cost = min(cost, max(nums[prev], nums[idx]) + solve(nums, idx+1, idx+2));
        cost = min(cost, max(nums[idx], nums[idx+1]) + solve(nums, prev, idx+2));
        cost = min(cost, max(nums[prev], nums[idx+1]) + solve(nums, idx, idx+2));
        return dp[prev][idx] = cost;
    }
    
    int minCost(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 1);
    }
};
