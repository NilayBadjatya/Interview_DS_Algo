class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        int pairsCount = 0;
        unordered_map<int, int> mp;
        for(auto& x: nums){
            mp[x]++;
        }
        for(auto& x : mp){
            pairsCount += x.second / 2;
        }
        return pairsCount == n / 2;
    }
};
