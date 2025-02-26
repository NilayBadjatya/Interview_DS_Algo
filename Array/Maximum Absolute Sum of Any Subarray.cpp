class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size(), sum = 0, maxSum = 0;
        //Kadane's Algorithm
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum < 0){
                sum = 0;
            }
            maxSum = max(maxSum, sum);
        }
        // Reverse Kadane's Algorithm
        sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum > 0){
                sum = 0;
            }
            maxSum = max(maxSum, abs(sum));
        }
        return maxSum;
    }
};
