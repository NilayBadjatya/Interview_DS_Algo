// Approach 1 : Using DFS (inRecursion Method)
class Solution {
  public:
  
    bool dfs(unordered_map<int, vector<int>>& adj, int i, vector<bool>& visited, vector<bool>& inRecursion){
        visited[i] = true;
        inRecursion[i] = true;
        for(auto& v : adj[i]){
            if(visited[v]){
                if(inRecursion[v]){
                    return true;
                }
            }
            if(dfs(adj, v, visited, inRecursion)){
               return true;
            }
        }
        inRecursion[i] = false;
        return false;
    }
  
    bool isCyclic(int n, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i] && dfs(adj, i, visited, inRecursion)){
                return true;
            }
        }
        return false;
    }
};

// Approach 2 : Topological Sort (BFS) (Also known as Kanh's Algorithm)
class Solution {
  public:
    bool isCyclic(int n, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n, 0);
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto& v : adj[node]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(inDegree[i] != 0){
                return true;
            }
        }
        return false;
    }
};
