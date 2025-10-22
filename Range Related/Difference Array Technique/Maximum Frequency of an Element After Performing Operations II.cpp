class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOps) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        map<int, int> mp, f;
        for(int i = 0; i < n; i++){
            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxEle);
            mp[l]++;
            mp[r+1]--;
            mp[nums[i]] += 0;
            f[nums[i]]++;
        }
        int cumSum = 0, result = 0;
        for(auto& x : mp){
            int target = x.first;
            x.second += cumSum;
            int tempResult = f[target] + min(x.second - f[target], numOps);
            result = max(result, tempResult);
            cumSum = x.second;
        }
        return result;
    }
};
