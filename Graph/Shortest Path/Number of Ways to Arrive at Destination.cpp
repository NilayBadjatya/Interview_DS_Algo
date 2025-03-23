typedef long long ll;
typedef pair<ll, ll> P;
class Solution {
public:
    ll MOD = 1e9 + 7;
    int minimumTime(unordered_map<ll, vector<P>> &adj, ll src, ll n){
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<ll> result(n, LLONG_MAX);
        vector<int> count(n, 0);
        result[0] = 0;
        count[0]++;
        pq.push({0, 0});
        while(!pq.empty()){
            ll time = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            if(time > result[node]){
                continue;
            }
            for(auto& v : adj[node]){
                ll currNode = v.first;
                ll currTime = v.second;
                if(currTime + time < result[currNode]){
                    result[currNode] = currTime + time;
                    count[currNode] = count[node];
                    pq.push({currTime + time, currNode});
                }else if(currTime + time == result[currNode]){
                    count[currNode] = (count[currNode] + count[node]) % MOD;
                    // pq.push({currTime + time, currNode});
                }
            }
        }
        return count[n-1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<ll, vector<P>> adj;
        for(auto& e : roads){
            ll u = e[0];
            ll v = e[1];
            ll time = e[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        return minimumTime(adj, 0, n);
    }
};
