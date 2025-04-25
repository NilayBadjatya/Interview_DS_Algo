class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] += nums[i-1];
        }
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int rem = nums[i] % k;
            if(rem < 0) rem += k;
            if(mp.count(rem) != 0){
                ans += mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};
