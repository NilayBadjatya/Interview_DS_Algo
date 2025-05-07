typedef long long ll;
typedef pair<ll, pair<ll, ll>> P;
class Solution {
public:

    bool isSafe(ll i, ll j, ll n, ll m){
        return i < n && i >= 0 && j < m && j >= 0;
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        ll n = moveTime.size();
        ll m = moveTime[0].size();
        vector<vector<ll>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<ll>> res(n, vector<ll> (m, LLONG_MAX));
        res[0][0] = 0;
        pq.push({0, {0,0}});
        while(!pq.empty()){
            ll time = pq.top().first;
            ll i = pq.top().second.first;
            ll j = pq.top().second.second;
            pq.pop();
            for(auto& d : dir){
                ll x = i + d[0];
                ll y = j + d[1];
                if(isSafe(x, y, n, m)){
                    ll tempTime = time;
                    if(time < moveTime[x][y]){
                        tempTime = moveTime[x][y]+1;
                    }else{
                        tempTime++;
                    }
                    if(res[x][y] > tempTime){
                        res[x][y] = tempTime;
                        pq.push({tempTime, {x,y}});
                    }
                }
            }
        }
        return res[n-1][m-1];
    }
};
