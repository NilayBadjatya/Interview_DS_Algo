class Solution {
public:

    int solveAtMost(vector<int>& nums, int goal){
        int n = nums.size();
        int i = 0, j = 0, res = 0, sum = 0;
        while(j < n){
            sum += nums[j];
            if(sum <= goal){
                res += j - i + 1;
            }else if(sum > goal){
                while(i < j && sum > goal){
                    sum -= nums[i];
                    i++;
                }
                if(sum <= goal)
                res += j - i + 1;
            }
            j++;
        }
        return res;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solveAtMost(nums, goal) - solveAtMost(nums, goal-1);
    }
};
