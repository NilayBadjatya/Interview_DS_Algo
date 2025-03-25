class Solution {
  public:
    int dp[201][10001];
    bool solve(vector<int>& arr, int i, int sum, int val){
        if(sum > val){
            return false;
        }else if(sum == val){
            return true;
        }
        if(i == arr.size()){
            return false;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        return dp[i][sum] = solve(arr, i+1, sum+arr[i], val) || solve(arr, i+1, sum, val);
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, 0, 0, sum);
    }
};
