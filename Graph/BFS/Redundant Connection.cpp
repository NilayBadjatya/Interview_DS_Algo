class Solution {
public:

    bool bfs(unordered_map<int, vector<int>> &adj, int node1, int dest, int n){
        queue<int> q;
        q.push(node1);
        if(node1 == dest){
            return true;
        }
        vector<bool> visited(n, false);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(visited[node]) continue;
            visited[node] = true;
            if(node == dest){
                return true;
            }
            for(auto &v : adj[node]){
                if(!visited[v]){
                    q.push(v);
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n; i++){
            if(bfs(adj, edges[i][0], edges[i][1], n)){
                return edges[i];
            }
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return {};
    }
};
