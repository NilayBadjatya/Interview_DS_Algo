// Approach 1 : Using DFS

class Solution {
public:

    bool dfs(vector<vector<int>>& graph, int i, int c, vector<int>& color){
        color[i] = c;
        for(auto& v : graph[i]){
            if(color[v] == -1){
                color[v] = 1 - color[i];
                if(!dfs(graph, v, color[v], color)){
                    return false;
                }
            }else if(color[v] == c){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1 && !dfs(graph, i, 0, color)){
                return false;
            }
        }
        return true;
    }
};

// Approach 2 : Using BFS

class Solution {
public:

    bool bfs(vector<vector<int>>& graph, int i, int c, vector<int>& color){
        queue<int> q;
        q.push(i);
        color[i] = c;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto& v : graph[node]){
                if(color[v] == color[node]){
                    return false;
                }else if(color[v] == -1){
                    color[v] = 1 - color[node];
                    q.push(v);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1 && !bfs(graph, i, 0, color)){
                return false;
            }
        }
        return true;
    }
};
