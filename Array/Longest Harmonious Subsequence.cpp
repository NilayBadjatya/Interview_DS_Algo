class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, ans = 0;
        while(j < n){
            while(i < j && nums[j]  - nums[i] > 1){
                i++;
            }
            if(nums[j] - nums[i] == 1)
                ans = max(ans, j - i + 1);
            j++;
        }
        return ans == 1 ? 0 : ans;
    }
};
