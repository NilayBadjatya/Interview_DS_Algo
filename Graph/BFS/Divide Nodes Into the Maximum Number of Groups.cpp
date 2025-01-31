class Solution {
public:

    bool isGraphBipartite(unordered_map<int, vector<int>> &adj, int node, int c, vector<int> &color){
        color[node] = c;
        for(auto &v : adj[node]){
            if(color[v] == c){
                return false;
            }else if(color[v] == -1){
                color[v] = 1 - c;
                if(!isGraphBipartite(adj, v, color[v], color)){
                    return false;
                }
            }
        }
        return true;
    }

    int bfs(unordered_map<int, vector<int>> &adj, int i, int n){
        int level = 0;
        vector<int> visited(n, false);
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();
                if(visited[node]) continue;
                visited[node] = true;
                for(auto &v : adj[node]){
                    if(!visited[v]){
                        q.push(v);
                    }
                }
            }
            level++;
        }
        return level;
    }

    int findMaxLevel(unordered_map<int, vector<int>> &adj, int i, vector<int> &levels, int n, vector<bool> &visited){
        int level = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();
                if(visited[node]) continue;
                visited[node] = true;
                level = max(level, levels[node]);
                for(auto &v : adj[node]){
                    if(!visited[v]){
                        q.push(v);
                    }
                }
            }
        }
        return level;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        // Checking if given graph is Bipartite or not.
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1 && !isGraphBipartite(adj, i, 1, color)){
                return -1;
            }
        }
        vector<int> levels(n, 0);
        for(int i = 0; i < n; i++){
            levels[i] = bfs(adj, i, n); 
        }
        int num = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                num += findMaxLevel(adj, i, levels, n, visited);
            }
        }
        return num;
    }
};
