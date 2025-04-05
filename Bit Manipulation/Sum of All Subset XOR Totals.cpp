class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int i = 0; i< n; i++){
            result |= nums[i];
        }
        return result << n-1;
    }
};
