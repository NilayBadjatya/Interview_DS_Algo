class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int a = 1, b = 1, res1  =INT_MIN;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                a++;
            }else{
                a = 1;
            }
            res1 = max(res1, a);
        }
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                b++;
            }else{
                b = 1;
            }
            res1 = max(res1, b);
        }
        return res1 == INT_MIN ? 1 : res1;
    }
};
