class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int furthest = 0;
        for(int i = 0; i < n-1; i++){
            furthest = max(furthest, i + nums[i]);
            if(furthest == i) return false;
        }
        return true;
    }
};
