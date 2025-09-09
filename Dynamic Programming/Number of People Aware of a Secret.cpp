class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[1001];
    int solve(int day, int delay, int forget){
        if(day == 1){
            return 1;
        }
        if(dp[day] != -1){
            return dp[day];
        }
        int result = 0;
        for(int d = day - forget + 1; d <= day - delay; d++){
            if(d > 0)
                result = (result + solve(d, delay, forget)) % MOD;
        }
        return dp[day] = result;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total = 0;
        memset(dp, -1, sizeof(dp));
        for(int d = n - forget + 1; d <= n; d++){
            total = (total + solve(d, delay, forget)) % MOD;
        }
        return total;
    }
};
