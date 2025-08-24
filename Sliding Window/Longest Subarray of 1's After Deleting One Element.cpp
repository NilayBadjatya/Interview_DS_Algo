class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, countOne = 0, countZero = 0, ans = INT_MIN;
        while(j < n){
            if(nums[j]){
                countOne++;
            }else{
                countZero++;
            }
            while(i < j && countZero > 1){
                if(nums[i]){
                    countOne--;
                }else{
                    countZero--;
                }
                i++;
            }
            ans = max(ans, countOne);
            j++;
        }
        return ans == n ? ans - 1 : ans;
    }
};
