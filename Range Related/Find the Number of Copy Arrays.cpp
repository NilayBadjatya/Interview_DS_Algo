class Solution {
public:
    int countArrays(vector<int>& nums, vector<vector<int>>& b) {
        int n = nums.size();
        int mini = b[0][0], maxi = b[0][1], diff = 0;
        for(int i = 1; i < n; i++){
            diff += (nums[i] - nums[i-1]);
            mini = max(mini, b[i][0] - diff);
            maxi = min(maxi, b[i][1] - diff);
        }
        return (maxi - mini + 1) < 0 ? 0 : (maxi - mini + 1);
    }
};
