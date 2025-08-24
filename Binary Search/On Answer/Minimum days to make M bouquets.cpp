class Solution {
  public:
  
    int isValid(vector<int>& arr, int mid, int m, int k){
        int count = 0, n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[i] <= mid){
                count++;
            }else{
                count = 0;
            }
            if(count == k){
                m--;
                count = 0;
            }
        }
        if(count == k){
            m--;
        }
        return m <= 0;
    }
  
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int n = arr.size();
        if(m * k > n) return -1;
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isValid(arr, mid, m, k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
