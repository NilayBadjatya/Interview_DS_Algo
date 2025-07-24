typedef long long ll;
class Solution {
public:
    ll MOD = 1e9 + 7;
    ll nCr(ll n, ll r){
        return 1LL * n * (n-1) / 2;
    }

    ll countTrapezoids(vector<vector<int>>& points) {
        unordered_map<ll, ll> mp;
        for(auto& p : points){
            ll x = p[0];
            ll y = p[1];
            mp[y]++;
        }
        vector<ll> a;
        for(auto& x : mp){
            if(x.second > 1){
                ll num = nCr(x.second, 2);
                a.push_back(num);
            }
        }
        if(a.size() < 2){
            return 0;
        }
        ll prefix = 0, ans = 0;
        for(ll i = 0; i < a.size(); i++){
            ans = (ans + (1LL * a[i] * prefix) % MOD) % MOD;
            prefix += a[i];
        }
        return ans;
    }
};
