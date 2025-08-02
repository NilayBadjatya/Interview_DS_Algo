class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        int mini = INT_MAX;
        unordered_map<int, int> mp;
        for(auto& x : basket1){
            mp[x]++;
            mini = min(mini, x);
        }
        for(auto& x : basket2){
            mp[x]--;
            mini = min(mini, x);
        }
        vector<int> a;
        for(auto& x : mp){
            int freq = abs(x.second);
            if(freq % 2 != 0) return -1;
            if(freq == 0) continue;
            freq /= 2;
            while(freq--){
                a.push_back(x.first);
            }
        }
        sort(a.begin(), a.end());
        int i = 0, sz = a.size();
        long long ans = 0;
        while(i < (sz/2)){
            ans += min(a[i], mini * 2);
            i++;
        }
        return ans;
    }
};
