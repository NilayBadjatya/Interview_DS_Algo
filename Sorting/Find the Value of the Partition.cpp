class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minPairDiff = INT_MAX;
        for(int i = 1; i < nums.size(); i++){
            minPairDiff = min(minPairDiff, nums[i] - nums[i-1]);
        }
        return minPairDiff;
    }
};
