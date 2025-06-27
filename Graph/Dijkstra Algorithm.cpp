// Time Complexity - O(E + VlogV) with priority_queue
// if with normal queue then O(V^2)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int, vector<vector<int>>> adj;
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        queue<pair<int, int>> q;
        q.push({0, src});
        vector<int> result(V, INT_MAX);
        result[src] = 0;
        while(!q.empty()){
            int w = q.front().first;
            int node = q.front().second;
            q.pop();
            // visited[node] = true;
            for(auto& v : adj[node]){
                int curr = v[1];
                int currNode = v[0];
                if(result[currNode] > w + curr){
                    result[currNode] = w + curr;
                    q.push({result[currNode], currNode});
                }
            }
        }
        return result;
    }
};
