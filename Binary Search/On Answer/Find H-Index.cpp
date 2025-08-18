class Solution {
  public:
  
    bool isValid(vector<int>& nums, int h){
        int n = nums.size();
        int c = 0, c_h = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) c++;
            if(nums[i] >= h) c_h++;
        }
        return c >= h && c_h >= h;
    }
  
    int hIndex(vector<int>& nums) {
        // code here
        int l = 0, r = *max_element(nums.begin(), nums.end()), ans = INT_MIN;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(isValid(nums, mid)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};
