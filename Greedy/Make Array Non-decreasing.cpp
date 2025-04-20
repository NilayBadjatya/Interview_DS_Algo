class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0], size = n;
        for(int i = 1; i < n; i++){
            if(nums[i] < maxi){
                size--;
            }else{
                maxi = nums[i];
            }
        }
        return size;
    }
};
