class Solution {
public:
    int dp[301][302];
    int MOD = 1e9 + 7;
    long long findPower(int a, int b){
        if(b == 0){
            return 1;
        }
        long long half = findPower(a, b/2);
        long long result = (half * half) % MOD;
        if(b % 2 != 0){
            result = (result * a) % MOD;
        }
        return result;
    }

    int solve(int n, int x, int st){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n][st] != -1){
            return dp[n][st];
        }
        int power = findPower(st, x);
        if(power > n) return 0;
        int take = solve(n - power, x, st+1);
        int skip = solve(n, x, st+1);
        return dp[n][st] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        return solve(n, x, 1);
    }
};
