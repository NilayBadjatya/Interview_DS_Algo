//Time Complexity - O(N*M*K)
class Solution {
public:
    int n;
    int dp[2001][2001][2];
    int solve(vector<int>& nums, int i, int canExtend, int k, int m){
        if(i == n){
            if(k > 0){
                return -1e9;
            }
            return 0;
        }
        if(dp[i][k][canExtend] != -1){
            return dp[i][k][canExtend];
        }
        int take = -1e9, skip = -1e9;
        if(canExtend){
            take = nums[i] + solve(nums, i+1, 1, k, m);
            skip = solve(nums, i, 0, k, m);
        }else{
            if(k == 0) return 0;
            if(i + m <= n){
                int currSum = 0;
                for(int j = i; j < i+m; j++){
                    currSum += nums[j];
                }
                take = currSum + solve(nums, i + m, 1, k-1, m);
            }
            skip = solve(nums, i+1, 0, k, m);
        }
        return dp[i][k][canExtend] = max(take, skip);
    }

    int maxSum(vector<int>& nums, int k, int m) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, k, m);
    }
};
