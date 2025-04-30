typedef long long ll;
typedef pair<ll, ll> P;
class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> dijktras(unordered_map<ll, vector<vector<ll>>>& adj, ll src, ll n){
        vector<int> result(n+1, INT_MAX);
        result[0] = 1;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({src, 1});
        while(!pq.empty()){
            ll node = pq.top().first;
            ll w = pq.top().second;
            pq.pop();
            for(auto& v : adj[node]){
                ll currNode = v[0];
                ll currW = v[1];
                if(result[currNode] > (currW * w) % MOD){
                    result[currNode] = (currW * w) % MOD;
                    pq.push({currNode, result[currNode]});
                }
            }
        }
        return result;
    }
    
    vector<int> baseUnitConversions(vector<vector<int>>& c) {
        unordered_map<ll, vector<vector<ll>>> adj;
        ll n = c.size();
        for(auto& e : c){
            ll u = e[0];
            ll v = e[1];
            ll w = e[2];
            adj[u].push_back({v, w});
        }
        vector<int> res = dijktras(adj, 0, n);
        return res;
    }
};
