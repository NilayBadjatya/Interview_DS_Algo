class Solution {
  public:
  
    bool isValid(vector<int>& arr, long long mid, long long k){
        long long n = arr.size();
        long long ops = 0;
        if(n % 2 == 0){
            ops += max(0LL, 2 * mid - arr[n/2-1] - arr[n/2]);
        }else{
            ops += max(0LL, mid - arr[n/2]);
        }
        for(long long i = n/2+1; i < n; i++){
            if(arr[i] >= mid) continue;
            ops += mid - arr[i];
        }
        return ops <= k;
    }
  
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        long long n = arr.size();
        sort(arr.begin(), arr.end());
        long long low = arr[0];
        long long high = arr[n-1] + k;
        long long ans = -1;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(isValid(arr, mid, k)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};
