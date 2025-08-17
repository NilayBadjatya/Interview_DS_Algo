class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(auto& it : nums){
            it = abs(it);
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int it = upper_bound(nums.begin(), nums.end(), nums[i] * 2) - nums.begin();
            it--;
            if(it != n){
                ans += (it - i);
            }
        }
        return ans;
    }
};
