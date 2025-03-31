typedef long long ll;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<ll> pairSum;
        for(int i = 1; i < n; i++){
            ll sum = weights[i] + weights[i-1];
            pairSum.push_back(sum);
        }
        sort(pairSum.begin(), pairSum.end());
        ll sum = 0;
        for(int i = 0; i < k-1; i++){
            sum += (pairSum[n-2-i] - pairSum[i]);
        }        
        return sum;
    }
};
