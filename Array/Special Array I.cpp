class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int x = nums[0] % 2;
        for(int i = 1; i < n; i++){
            if(nums[i] % 2 == x){
                return false;
            }
            x = nums[i] % 2;
        }
        return true;
    }
};
