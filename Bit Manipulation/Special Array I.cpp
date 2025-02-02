class Solution {
public:
    //Bit Manipulation
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++){
            int x = nums[i-1] & 1;
            int y = nums[i] & 1;
            if(x == y) return false;
        }
        return true;
    }
};
