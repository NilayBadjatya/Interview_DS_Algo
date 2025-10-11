class Solution {
public:
    long long solve(vector<int>& power, int i, 
                        vector<long long>& dp, unordered_map<int, int>& mp) {
        if (i == power.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        long long take = 0, skip = 0;
        int idx = lower_bound(power.begin(), power.end(), power[i] + 3) - power.begin();
        take = 1LL * power[i] * mp[power[i]] + solve(power, idx, dp, mp);
        skip = solve(power, i + 1, dp, mp);
        return dp[i] = max(take, skip);
    }

    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        sort(power.begin(), power.end());
        unordered_map<int, int> mp;
        for(auto& x : power){
            mp[x]++;
        }
        vector<long long> dp(n + 1, -1);
        return solve(power, 0, dp, mp);
    }
};
