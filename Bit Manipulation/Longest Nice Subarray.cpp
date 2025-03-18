class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        int i = 0, j = 0, mask = 0;
        while(j < n){
            while((mask & nums[j]) != 0){
                mask ^= nums[i++];
            }
            mask |= nums[j];
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
