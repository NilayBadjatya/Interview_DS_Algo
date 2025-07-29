class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> bits(32, -1);
        for(int i = n-1; i >= 0 ; i--){
            for(int j = 0; j < 32 ; j++){
                if((nums[i] >> j) & 1){
                    bits[j] = i;
                }
            }
            int maxIdx = i;
            for(int j = 0; j < 32; j++){
                if(bits[j] != -1){
                    maxIdx = max(maxIdx, bits[j]);
                }
            }
            ans[i] = maxIdx - i + 1;
        }
        return ans;
    }
};
