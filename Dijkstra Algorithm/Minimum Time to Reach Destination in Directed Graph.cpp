typedef pair<int, int> P;
class Solution {
public:
    
    int minTime(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<vector<int>>> adj;
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int start = e[2];
            int end = e[3];
            adj[u].push_back({v, start, end});
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,0});
        vector<int> visited(n, INT_MAX);
        while(!pq.empty()){
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node == n-1) return t;
            if(visited[node] <= t) continue;
            visited[node] = t;
            for(auto& edge : adj[node]){
                int v = edge[0];
                int st = edge[1];
                int en = edge[2];
                if(t > en) continue;
                int newT = max(t, st) + 1;
                if(visited[v] > newT){
                    // visited[v] = newT;
                    pq.push({newT, v});
                }
            }
        }
        return -1;
    }
};
