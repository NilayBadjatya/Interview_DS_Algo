class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int len = 0, n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++){
            if(maxi == nums[i]){
                len++;
                ans = max(ans, len);
            }else{
                len = 0;
            }
        }
        return ans;
    }
};
