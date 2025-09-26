class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        if(n < 3) return 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int thirdSide = nums[i] + nums[j];
                int idx = lower_bound(nums.begin(), nums.end(), thirdSide) - nums.begin();
                if(idx - j - 1 > 0)
                    ans += idx - j - 1;
            }
        }
        return ans;
    }
};
