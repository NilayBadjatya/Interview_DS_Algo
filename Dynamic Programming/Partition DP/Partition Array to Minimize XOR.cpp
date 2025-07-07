class Solution {
public:

    int solve(vector<int>& nums, int i, int k, vector<vector<int>>& dp){
        if(k == 0 && i == nums.size()){
            return 0;
        }
        if(i == nums.size() || k == 0){
            return INT_MAX;
        }
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        int xorr = 0, ans = INT_MAX;
        for(int j = i; j < nums.size(); j++){
            xorr ^= nums[j];
            int newXorr = solve(nums, j+1, k-1, dp);
            ans = min(ans, max(newXorr, xorr));
        }
        return dp[i][k] = ans;
    }

    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
        return solve(nums, 0, k, dp);
    }
};
