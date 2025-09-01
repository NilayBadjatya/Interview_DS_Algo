typedef long long ll;
class Solution {
public:

    void solve(vector<ll>& divs, ll i, ll prod, vector<int>& path, ll k, ll n, vector<int>& res){
        if(prod == n && path.size() == k){
            if(res.empty() || (res.back() - res[0] > path.back() - path[0])){
                res = path;
            }
            return;
        }
        if(path.size() > k || i == divs.size() || prod > n) return;
        path.push_back(divs[i]);
        // solve(divs, i+1, prod * divs[i], path, k, n, res);
        solve(divs, i, prod * divs[i], path, k, n, res);
        path.pop_back();
        solve(divs, i+1, prod, path, k, n, res);
    }

    vector<int> minDifference(int n, int k) {
        vector<ll> divs;
        for(ll i = 1; i * i <= n; i++){
            if(n % i == 0){
                divs.push_back(i);
                if((n / i) != i)
                    divs.push_back(n/i);
            }
        }
        sort(divs.begin(), divs.end());
        vector<int> path;
        vector<int> res;
        solve(divs, 0, 1, path, k, n, res);
        return res;
    }
};
