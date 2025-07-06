typedef long long ll;
typedef pair<ll, vector<ll>> P;
class Solution {
public:

    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<ll>> result(m, vector<ll> (n, LLONG_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({1, {0, 0, 1}});
        vector<vector<ll>> dir = {{0, 1}, {1, 0}};
        result[0][0] = 1;
        while(!pq.empty()){
            ll cost = pq.top().first;
            ll i = pq.top().second[0];
            ll j = pq.top().second[1];
            ll time = pq.top().second[2];
            pq.pop();
            if(time % 2 == 0){
                cost += waitCost[i][j];
                if(result[i][j] != LLONG_MAX){
                    // result[i][j] += waitCost[i][j];
                }
                time++;
            }
            time++;
            for(auto& v : dir){
                ll x = i + v[0];
                ll y = j + v[1];
                ll tempCost = (x+1) * (y+1) + cost;
                if(isValid(x, y, m, n) && result[x][y] > tempCost){
                    result[x][y] = tempCost;
                    pq.push({tempCost, {x, y, time}});
                }
            }
        }
        return result[m-1][n-1];
    }
};
