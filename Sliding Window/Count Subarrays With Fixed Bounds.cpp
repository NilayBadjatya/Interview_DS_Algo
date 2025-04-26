class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int i = -1, j = 0, mini = -1, maxi = -1;
        long long ans = 0;
        while(j < n){
            if(nums[j] < minK || nums[j] > maxK){
                i = j;
            }
            if(minK == nums[j]) mini = j;
            if(maxK == nums[j]) maxi = j;
            if(min(maxi, mini) - i > 0){
                ans += min(maxi, mini) - i;
            }
            j++;
        }
        return ans;
    }
};
