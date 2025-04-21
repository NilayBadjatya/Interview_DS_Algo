typedef long long ll;
class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        int n = diff.size();
        ll prev = lower, maxi = lower, mini = lower;
        for(int i = 0; i < n; i++){
            ll x = diff[i] + prev;
            prev = x;
            maxi = max(maxi, prev);
            mini = min(mini, prev);
        }
        ll x = (upper - lower + 1) - (maxi - mini);
        return x < 0 ? 0 : x;
    }
};
