typedef long long ll;
class Solution {
public:
    ll count;

    ll dfs(unordered_map<ll, vector<ll>>& adj, ll node, ll parent, vector<int>& cost){
        ll ans = cost[node];
        vector<ll> childCost;
        for(auto& v : adj[node]){
            if(v == parent) continue;
            ll childAns = dfs(adj, v, node, cost);
            childCost.push_back(childAns);
        }
        if(childCost.size() == 0){
            return ans;
        }
        ll maxCost = *max_element(childCost.begin(), childCost.end());
        for(auto& x : childCost){
            if(x != maxCost){
                count++;
            }
        }
        return maxCost + ans;
    }


    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        unordered_map<ll, vector<ll>> adj;
        for(auto& e : edges){
            ll u = e[0];
            ll v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        count = 0;
        dfs(adj, 0, -1, cost);
        return count;
    }
};
