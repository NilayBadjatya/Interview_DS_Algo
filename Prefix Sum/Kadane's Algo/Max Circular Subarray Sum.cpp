class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = arr[0];
        suffix[n-1] = arr[n-1];
        int sum = arr[0];
        for(int i = 1; i < n; i++){
            sum += arr[i];
            prefix[i] = max(prefix[i-1], sum);
        }
        
        sum = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            sum += arr[i];
            suffix[i] = max(suffix[i+1], sum);
        }
               
        int maxi_sum = INT_MIN;
        for(int i = 1; i < n; i++){
            maxi_sum = max(maxi_sum, suffix[i] + prefix[i-1]);
        }
        int kadane_sum = 0;
        for(int i = 0; i < n; i++){
            kadane_sum += arr[i];
            maxi_sum = max(maxi_sum, kadane_sum);
            if(kadane_sum < 0){
                kadane_sum = 0;
            }
        }
        return maxi_sum;
    }
};
