class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, maxLen = 0;
        int count = 0;
        while (j < n) {
            if(nums[j] == 0){
                count++;
            }
            while(count > k && i < j){
                if(nums[i] == 0){
                    count--;
                }
                i++;
            }
            if(count <= k)
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};
