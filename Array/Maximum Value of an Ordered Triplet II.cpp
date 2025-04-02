typedef long long ll;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<ll> maxiRight(n), maxiLeft(n);
        maxiLeft[0] = nums[0];
        maxiRight[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            maxiLeft[i] = max(maxiLeft[i-1], (ll)nums[i]);
        }
        for(int i = n-2; i >= 0; i--){
            maxiRight[i] = max(maxiRight[i+1], (ll)nums[i]);
        }
        ll res = 0;
        for(int j = 1; j < n-1; j++){
            res = max(res, (maxiLeft[j-1] - nums[j]) * maxiRight[j+1]);
        }
        return res;
    }
};
