class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        vector<int> diff(maxEle + 1, 0);
        unordered_map<int, int> mp;
        // Applying standard diff array technique
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            int l = max(nums[i] - k, 0);
            int r = nums[i] + k;
            diff[l]++;
            if(r + 1 < diff.size()){
                diff[r+1]--;
            }
        }
        // Applying cumulative sum to calculate the overall frequencies.
        int maxFreq = 0;
        for(int i = 1; i < diff.size(); i++){
            diff[i] += diff[i-1];
            int tempResult = mp[i] + min(diff[i] - mp[i], numOperations);
            maxFreq = max(maxFreq, tempResult);
        }
        return maxFreq;
    }
};
