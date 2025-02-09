class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<long long, long long> mp, history;
        for(long long i = 0; i < n; i++){
            mp[nums[i] - i]++;
        }
        long long count = 0;
        for(long long i = 0; i < n; i++){
            count += n - (i + 1) - (mp[nums[i]-i] - 1 - history[nums[i] - i]);
            history[nums[i] - i]++;
        }
        return count;
    }
};
