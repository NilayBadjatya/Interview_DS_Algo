class Solution {
  public:
    int dp[1001][1001];
    int solve(vector<int>& arr, int i, int j){
        if(i == j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int k = i; k < j; k++){
            int steps = arr[i-1] * arr[k] * arr[j] + (solve(arr, i, k) + solve(arr, k+1, j));
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(arr, 1, n-1);
    }
};
