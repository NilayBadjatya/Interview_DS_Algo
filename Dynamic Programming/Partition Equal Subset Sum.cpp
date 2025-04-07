//C++ Code
class Solution {
public:
    int dp[201][20001];
    bool solve(vector<int>& nums, int i, int currSum, int sum) {
        if (i == nums.size() || currSum > sum) {
            return false;
        }
        if (currSum == (sum - currSum)) {
            return true;
        }
        if (dp[i][currSum] != -1) {
            return dp[i][currSum];
        }
        return dp[i][currSum] = solve(nums, i + 1, currSum + nums[i], sum) ||
                                solve(nums, i + 1, currSum, sum);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, sum);
    }
};

//Java Code
class Solution {

    int[][] dp;

    private boolean solve(int[] nums, int i, int currSum, int sum) {
        if (i == nums.length || currSum > sum) {
            return false;
        }
        if (currSum == (sum - currSum)) {
            return true;
        }
        if (dp[i][currSum] != -1) {
            return dp[i][currSum] == 1;
        }
        boolean res = solve(nums, i + 1, currSum + nums[i], sum)
                || solve(nums, i + 1, currSum, sum);
        dp[i][currSum] = res ? 1 : 0;
        return res;
    }

    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) {
            return false;
        }
        dp = new int[n][sum];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return solve(nums, 0, 0, sum);
    }
}
