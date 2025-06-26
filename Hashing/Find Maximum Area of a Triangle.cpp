typedef long long ll;
class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        unordered_map<ll, pair<ll, ll>> mpx;
        unordered_map<ll, pair<ll, ll>> mpy;
        ll mnx = LLONG_MAX, mxx = LLONG_MIN;
        ll mny = LLONG_MAX, mxy = LLONG_MIN;
        for(auto& it : coords){
            ll x = it[0];
            ll y = it[1];
            if(mpx.find(x) == mpx.end()){
                mpx[x] = {LLONG_MIN, LLONG_MAX};
            }
            mpx[x].first = max(mpx[x].first, y);
            mpx[x].second = min(mpx[x].second, y);

            if(mpy.find(y) == mpy.end()){
                mpy[y] = {LLONG_MIN, LLONG_MAX};
            }
            mpy[y].first = max(mpy[y].first, x);
            mpy[y].second = min(mpy[y].second, x);
            mnx = min(mnx, x);
            mxx = max(mxx, x);
            mny = min(mny, y);
            mxy = max(mxy, y);
        }

        ll ans = -1;
        for(auto& x : mpx){
            ll b = x.second.first - x.second.second;
            ll h = max(abs(x.first - mnx), abs(x.first - mxx));
            if(b == 0 || h == 0) continue;
            ans = max(ans, b * h);
        }

        for(auto& x : mpy){
            ll b = x.second.first - x.second.second;
            ll h = max(abs(x.first - mny), abs(x.first - mxy));
            if(b == 0 || h == 0) continue;
            ans = max(ans, b * h);
        }
        return ans;
    }
};
