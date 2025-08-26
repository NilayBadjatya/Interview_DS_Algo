class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        int groups = n / k;
        unordered_map<int, int> mp;
        for(auto& x : nums){
            mp[x]++;
            if(mp[x] > groups) return false;
        }
        return true;
    }
};
