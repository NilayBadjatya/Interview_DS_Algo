typedef long long ll;
class Solution {
public:
    int MOD = 1e9 + 7;
    ll specialTriplets(vector<int>& nums) {
        ll n = nums.size();
        unordered_map<ll, ll> total, left;
        for(auto& x : nums){
            total[x]++;
        }

        ll triplets = 0;
        for(ll j = 0; j < n; j++){
            ll x = nums[j] * 2;
            if(left[x] > 0){
                ll right = (total[x] - (nums[j] == x)) - left[x];
                triplets = (triplets + (left[x] * right) % MOD) % MOD;
            }
            left[nums[j]]++;
        }
        return triplets;
    }
};
