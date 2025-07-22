class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        int sum = 0, maxi = 0;
        while(j < n){
            mp[nums[j]]++;
            sum += nums[j];
            while(mp[nums[j]] > 1){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                sum -= nums[i];
                i++;
            }
            maxi = max(maxi, sum);
            j++;
        }
        return maxi;
    }
};
