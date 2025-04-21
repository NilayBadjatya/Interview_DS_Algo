typedef long long ll;
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<ll> result(k, 0);
        vector<ll> prev(k, 0);
        for(auto& num : nums){
            int current_mod = num % k;
            vector<ll> curr(k, 0);
            curr[current_mod] = 1;
            for(int i = 0; i < k; i++){
                if(prev[i]){
                    ll product_mod = (i * current_mod) % k;
                    curr[product_mod] += prev[i];
                }
            }
            for(int i = 0; i < k; i++){
                result[i] += curr[i];
            }
            prev = curr;
        }
        return result;
    }
};
