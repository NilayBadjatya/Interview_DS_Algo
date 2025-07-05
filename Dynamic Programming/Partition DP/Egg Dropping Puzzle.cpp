class Solution {
public:
    int dp[1001][1001];

    int solve(int e, int f) {
        if (f == 0 || f == 1) return f;
        if (e == 1) return f;

        if (dp[e][f] != -1) return dp[e][f];

        int low = 1, high = f, ans = f;

        while (low <= high) {
            int mid = (low + high) / 2;

            int breakEgg, notBreakEgg;

            if (dp[e - 1][mid - 1] != -1)
                breakEgg = dp[e - 1][mid - 1];
            else
                breakEgg = solve(e - 1, mid - 1);

            if (dp[e][f - mid] != -1)
                notBreakEgg = dp[e][f - mid];
            else
                notBreakEgg = solve(e, f - mid);

            int temp = 1 + max(breakEgg, notBreakEgg);
            ans = min(ans, temp);

            if (breakEgg < notBreakEgg)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return dp[e][f] = ans;
    }

    int eggDrop(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k);
    }
};
