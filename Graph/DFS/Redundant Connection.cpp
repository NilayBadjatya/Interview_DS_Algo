class Solution {
public:

    bool dfs(unordered_map<int, vector<int>> &adj, int node, int dest, int parent){ 
        for(auto &v : adj[node]){
            if(v == parent) continue;
            if(v == dest) return true;
            if(dfs(adj, v, dest, node)){
                return true;
            }
        }   
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> adj;
        adj[edges[0][0]].push_back(edges[0][1]);
        adj[edges[0][1]].push_back(edges[0][0]);
        vector<int> red;
        for(int i = 1; i < n; i++){
            if(dfs(adj, edges[i][0], edges[i][1], -1)){
                red = edges[i];
            }else{
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
            }
        }
        return red;
    }
};
