class Solution {
public:
    int solve(vector<int>& nums, int i, int j, int len, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int sum = 0, currMaxi = INT_MIN;
        for (int k = i; k <= j; k++) {
            currMaxi = max(currMaxi, nums[k]);
            if (k - i + 1 <= len) {
                sum = max(sum, currMaxi * (k - i + 1) +
                                   solve(nums, k + 1, j, len, dp));
            }
        }
        return dp[i][j] = sum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(arr, 0, n - 1, k, dp);
    }
};


// Precomputing the maximum values but this is overkill
class Solution {
public:
    int solve(vector<int>& nums, int i, int j, int len,
              vector<vector<int>>& maxi, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int sum = 0;
        for (int k = i; k <= j; k++) {
            if (k - i + 1 <= len) {
                sum = max(sum, maxi[i][k] * (k - i + 1) +
                                   solve(nums, k + 1, j, len, maxi, dp));
            }
        }
        return dp[i][j] = sum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> maxi(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int x = INT_MIN;
                for (int k = i; k <= j; k++) {
                    x = max(x, arr[k]);
                    maxi[i][j] = x;
                }
            }
        }
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(arr, 0, n - 1, k, maxi, dp);
    }
};
