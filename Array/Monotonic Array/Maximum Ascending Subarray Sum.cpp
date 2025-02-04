class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), sum = nums[0], maxi = *max_element(nums.begin(), nums.end());
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                sum += nums[i];
                maxi = max(maxi, sum);
            }else{
                sum = nums[i];
            }
        }
        return maxi;
    }
};
