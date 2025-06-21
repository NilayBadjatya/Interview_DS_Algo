typedef long long ll;
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        ll n = nums.size();
        
        vector<ll> minRight(n), maxRight(n);
        minRight[n-1] = nums[n-1];
        maxRight[n-1] = nums[n-1];
        for(ll i = n-2; i >= 0; i--){
            minRight[i] = min(minRight[i+1], (ll)nums[i]);
            maxRight[i] = max(maxRight[i+1], (ll)nums[i]);
        }

        long long prod = LLONG_MIN;
        for(ll i = 0; i < n; i++){
            if(i+m-1 < n){
                ll maxi = maxRight[i+m-1];
                ll mini = minRight[i+m-1];
                long long temp = max(maxi * nums[i], mini * nums[i]);
                prod = max(prod, temp);
            }
        }

        return prod;
    }
};
