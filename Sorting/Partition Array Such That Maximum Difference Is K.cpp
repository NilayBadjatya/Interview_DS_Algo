class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = n-2, j = n-1, count = 0;
        while(i >= 0){
            if((nums[j] - nums[i]) > k){
                count++;
                j = i;
            }
            i--;
        }
        return count+1;
    }
};
