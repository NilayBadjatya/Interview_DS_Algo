// User function Template for C++
class Solution {
  public:
    int solve(string& s, int i, int j, bool isTrue, vector<vector<vector<int>>>& dp){
        if(i == j){
            if(isTrue){
                return s[i] == 'T';
            }else{
                return s[i] == 'F';
            }
        }
        if(dp[i][j][isTrue] != -1){
            return dp[i][j][isTrue];
        }
        int ways = 0;
        for(int k = i+1; k < j; k += 2){
            int l1 = solve(s, i, k-1, 1, dp);
            int l0 = solve(s, i, k-1, 0, dp);
            int r1 = solve(s, k+1, j, 1, dp);
            int r0 = solve(s, k+1, j, 0, dp);
            if(isTrue){
                if(s[k] == '&'){
                    ways += l1 * r1;
                }else if(s[k] == '|'){
                    ways += (l1 * r1) + (l1 * r0) + (l0 * r1);
                }else{
                    ways += (l1 * r0) + (l0 * r1);
                }
            }else{
                if(s[k] == '&'){
                    ways += (l1 * r0) + (l0 * r1) + (l0 * r0);
                }else if(s[k] == '|'){
                    ways += (l0 * r0);
                }else{
                    ways += (l1 * r1) + (l0 * r0);
                }
            }
        }
        return dp[i][j][isTrue] = ways;
    }
  
    int countWays(string &s) {
        // code here
        int n = s.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1, vector<int> (2, -1)));
        return solve(s, 0, n-1, 1, dp);
    }
};
