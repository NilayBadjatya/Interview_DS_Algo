typedef long long ll;
class Solution {
public:

    ll factorial(ll x){
        ll n = x;
        if(n == 0) return 1;
        for(ll i = 1; i < n; i++){
            x *= i;
        }
        return x;
    }

    long long countGoodIntegers(int n, int k) {
        ll d = (n+1) / 2;
        ll left = pow(10, d-1);
        ll right = pow(10, d);
        ll cnt = 0;
        unordered_set<string> st;
        for (ll i = left; i < right; i++) {
            string s = to_string(i);
            string rev = s;
            if(n % 2 != 0){
                rev.pop_back();
            }
            reverse(rev.begin(), rev.end());
            s += rev;
            ll x = stoll(s);
            if(x % k == 0){
                sort(s.begin(), s.end());
                st.insert(s);
            }
        }
        for(auto& s : st){
            vector<ll> freq(10, 0);
            for(auto& ch : s){
                freq[ch - '0']++;
            }
            ll total = s.length();
            ll fact = factorial(total-1);
            fact *= (total - freq[0]);
            for(auto& x : freq){
                ll f = factorial(x);
                fact /= f;
            }
            cnt += fact;
        }
        return cnt;
    }
};
