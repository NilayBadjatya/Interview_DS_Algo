class Solution {
  public:
  
    bool isValid(vector<int>& nums, int mid, int k){
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > mid){
                return false;
            }
            if(sum + nums[i] > mid){
                if(k == 0){
                    return false;
                }
                k--;
                sum = nums[i];
            }else{
                sum += nums[i];
            }
        }
        return true;
    }
  
    int splitArray(vector<int>& arr, int k) {
        // code here
        int l = *min_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        int ans = INT_MAX;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(isValid(arr, mid, k-1)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        
        return ans;
    }
};
