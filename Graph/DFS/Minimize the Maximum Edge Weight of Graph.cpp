class Solution {
public:

    void dfs(unordered_map<int, vector<vector<int>>>& adj, int i, vector<bool>& visited, int mid){
        visited[i] = true;
        for(auto& v : adj[i]){
            if(!visited[v[0]]){
                if(v[1] > mid) continue;
                dfs(adj, v[0], visited, mid);
            }
        }
    }

    bool isValid(int n, unordered_map<int, vector<vector<int>>>& adj, int mid, int threshold){
        vector<bool> visited(n, false);
        dfs(adj, 0, visited, mid);
        for(int i = 0; i < n; i++){
            if(!visited[i]) return false;
        }
        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<vector<int>>> adj;
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            // if(w > mid) continue;
            adj[v].push_back({u, w});
        }
        int l = 1, r = 1e6, ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(isValid(n, adj, mid, threshold)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
