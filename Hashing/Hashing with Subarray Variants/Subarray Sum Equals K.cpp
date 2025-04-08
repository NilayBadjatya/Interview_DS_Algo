//Approach 1: Using HashMap
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0]++;
        int sum = 0, res = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(mp.count(sum - k) != 0){
                res += mp[sum-k];
            }
            mp[sum]++;
        }
        return res;
    }
};
