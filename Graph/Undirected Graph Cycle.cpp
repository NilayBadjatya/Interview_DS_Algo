// Approach 1 : Using DFS
class Solution {
  public:
  
    bool dfs(unordered_map<int, vector<int>>& adj, int i, int parent, vector<bool>& visited){
        visited[i] = true;
        bool ans = true;
        for(auto& v : adj[i]){
            if(v == parent) continue;
            if(visited[v]) return false;
            ans = dfs(adj, v, i, visited);
        }
        return ans;
    }
  
    bool isCycle(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(!dfs(adj, i, -1, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

// Approach 2 : Using BFS
class Solution {
  public:
  
    bool bfs(unordered_map<int, vector<int>>& adj, int i, vector<bool>& visited){
        queue<pair<int, int>> q;
        visited[i] = true;
        q.push({i, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto& v : adj[node]){
                if(v == parent) continue;
                if(visited[v]) return true;
                q.push({v, node});
                visited[v] = true;
            }
        }
        return false;
    }
  
    bool isCycle(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i] && bfs(adj, i, visited)){
                return true;
            }
        }
        return false;
    }
};
