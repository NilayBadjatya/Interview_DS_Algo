class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxRight(n);
        maxRight[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            maxRight[i] = max(maxRight[i+1], nums[i]);
        }

        int maxi = -1;
        for(int i = 0; i < n-1; i++){
            if(maxRight[i+1] > nums[i]){
                maxi = max(maxi, maxRight[i+1] - nums[i]);
            }
        }

        return maxi;
    }
};
