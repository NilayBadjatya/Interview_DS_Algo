//Approach 1: Recursion + Memoization
class Solution {
public:
    int dp[2501][2501];
    int solve(vector<int>& nums, int i, int prev){
        if(i == nums.size()){
            return 0;
        }
        if(prev != -1 && dp[i][prev] != -1){
            return dp[i][prev];
        }
        int take = 0, skip = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + solve(nums, i+1, i);
        }
        skip = solve(nums, i+1, prev);
        if(prev != -1)
            return dp[i][prev] = max(take, skip);
        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, -1);
    }
};

//Approach 2: Bottom Up DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    t[i] = max(t[i], t[j]+1);
                    maxi = max(maxi, t[i]);
                }
            }
        }
        return maxi;
    }
};
