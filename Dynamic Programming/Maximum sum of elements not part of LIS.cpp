class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        // sort(arr.begin(), arr.end());
        int total = accumulate(arr.begin(), arr.end(), 0);
        vector<int> dp(n+1, 1);
        vector<int> sum = arr;
        int minSum = *min_element(arr.begin(), arr.end()), maxLen = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i]){
                    if(dp[i] <= dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        sum[i] = sum[j] + arr[i];
                    }
                    if(dp[i] > maxLen){
                        maxLen = dp[i];
                        minSum = sum[i];
                    }else if(dp[i] == maxLen){
                        minSum = min(minSum, sum[i]);
                    }
                }
            }
        }
        return total - minSum;
    }
};
