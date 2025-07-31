class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int kadaneSum = INT_MIN, sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            kadaneSum = max(kadaneSum, sum);
            if(sum < 0){
                sum = 0;
            }
        }

        vector<int> prefix(n), suffix(n);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        sum = nums[0];
        for(int i = 1; i < n; i++){
            sum += nums[i];
            prefix[i] = max(prefix[i-1], sum);
        }
        sum = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            sum += nums[i];
            suffix[i] = max(suffix[i+1], sum);
        }

        int circularSum = INT_MIN;
        for(int i = 0; i < n-1; i++){
            int sum = prefix[i] + suffix[i+1];
            circularSum = max(circularSum, sum);
        }
        return max(circularSum, kadaneSum);
    }
};
