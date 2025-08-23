class Solution {
  public:
  
    bool isValid(vector<int> &arr, int mid, int k){
        int n = arr.size();
        int sum = 0;
        k--;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum > mid){
                sum = arr[i];
                k--;
            }
            if(arr[i] > mid) return false;
        }
        return k >= 0;
    }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) return -1;
        int l = *min_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        int ans = -2;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(isValid(arr, mid, k)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
