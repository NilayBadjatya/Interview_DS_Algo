typedef long long ll;
class Solution {
public:
    ll dp[50001][4][4];
    ll solve(int n, vector<vector<int>>& cost, int i, int prev, int rev_prev){
        if(i == n/2){
            return 0;
        }
        if(prev != -1 && rev_prev != -1 && dp[i][prev][rev_prev] != -1){
            return dp[i][prev][rev_prev];
        }
        ll sum = LLONG_MAX;
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(k == j || j == prev || k == rev_prev) continue;
                sum = min(sum, cost[i][j] + cost[n-i-1][k] + solve(n, cost, i+1, j, k));
            }
        }
        if(prev == -1 && rev_prev == -1){
            return sum;
        }
        return dp[i][prev][rev_prev] = sum;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        memset(dp, -1, sizeof(dp));
        return solve(n, cost, 0, -1, -1);
    }
};
