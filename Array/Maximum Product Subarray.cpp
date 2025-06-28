class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1, suff = 1, ans = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            pre *= nums[i];
            ans = max(ans, pre);
            if(pre == 0){
                pre = 1;
            }
        }
        for(int i = n-1; i >= 0; i--){
            suff *= nums[i];
            ans = max(ans, suff);
            if(suff == 0){
                suff = 1;
            }
        }
        return ans;
    }
};
