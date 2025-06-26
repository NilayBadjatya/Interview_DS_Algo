class Solution {
public:

    int dfs(unordered_map<int, vector<int>>& adj, int i, int parent, vector<bool>& hasApple){
        int time = 0;
        for(auto& v : adj[i]){
            if(v == parent) continue;
            int time1 = dfs(adj, v, i, hasApple);
            if(time1 > 0 || hasApple[v]){
                time += 2 + time1;
            }
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj, 0, -1, hasApple);
    }
};
