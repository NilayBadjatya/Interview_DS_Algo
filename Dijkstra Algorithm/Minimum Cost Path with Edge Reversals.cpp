typedef pair<int, int> P;
class Solution {
public:

    int dijktra(unordered_map<int, vector<vector<int>>>& adj, int src, int n){
        vector<int> result(n, 1e9);
        result[src] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto& v : adj[node]){
                if(result[v[0]] > dis + v[1]){
                    result[v[0]] = dis + v[1];
                    pq.push({result[v[0]], v[0]});
                }

                // if(result[node] > result[v[0]] + 2 * v[1]){
                //     result[node] = result[v[0]] + 2 * v[1];
                // }
            }
        }
        return result[n-1] == 1e9 ? -1 : result[n-1];
    }

    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<vector<int>>> adj;
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }
        return dijktra(adj, 0, n);
    }
};
