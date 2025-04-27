class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, ans = 0;
        while(j < n){
            if(j - i + 1 == 3){
                double sum = nums[i] + nums[j];
                if(sum == (nums[i+1] * 1.0 / 2)){
                    ans++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
