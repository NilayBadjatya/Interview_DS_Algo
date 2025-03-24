class Solution {
public:
    bool solve(vector<vector<int>>& q, int i, int k, int sum, int val,
               int idx, vector<vector<int>>& dp) {
        if (sum == val) {
            return true;
        }
        if (i == k || sum > val) {
            return false;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        bool take = false, skip = false;
        if (idx >= q[i][0] && idx <= q[i][1]) {
            take = solve(q, i + 1, k, sum + q[i][2], val, idx, dp);
            // skip = solve(q, i + 1, k, sum, val, idx, dp);
        }
        skip = solve(q, i + 1, k, sum, val, idx, dp);
        return dp[i][sum] = take || skip;
    }

    bool isValid(vector<int>& nums, vector<vector<int>>& q, int k) {
        int n = nums.size();
        int m = q.size();
        for (int i = 0; i < n; i++) {
            vector<vector<int>> dp(k+1, vector<int> (nums[i]+1, -1));
            bool ans = solve(q, 0, k, 0, nums[i], i, dp);
            if (!ans) {
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int l = 0, r = q.size(), ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(nums, q, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
