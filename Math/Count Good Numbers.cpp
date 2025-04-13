typedef long long ll;
class Solution {
public:
    int MOD = 1e9 + 7;
    ll binaryExpo(ll a, ll b){
        if(b == 0){
            return 1;
        }
        ll half = binaryExpo(a, b/2);
        ll result = (half * half) % MOD;
        if(b % 2 != 0){
            result = (result * a) % MOD;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        ll even = ceil(n * 1.0 / 2);
        ll odd = n - even;
        ll fiveP = binaryExpo(5, even);
        ll fourP = binaryExpo(4, odd);
        ll ans = (fiveP * fourP) % MOD;
        return ans;
    }
};
