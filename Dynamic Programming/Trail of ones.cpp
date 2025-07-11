class Solution {
  public:
    int dp[31][2][2];
    int solve(int n, int i, int prev, bool hasPair){
        if(i == n){
            if(hasPair) return 1;
            return 0;
        }
        if(prev != -1 && dp[i][prev][hasPair] != -1){
            return dp[i][prev][hasPair];
        }
        int count = 0;
        count += solve(n, i+1, 0, hasPair);
        if(prev == 1){
            count += solve(n, i+1, 1, true);
        }else{
            count += solve(n, i+1, 1, hasPair);
        }
        if(prev == -1) return count;
        return dp[i][prev][hasPair] = count;
    }
  
    int countConsec(int n) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(n, 0, -1, false);
    }
};
