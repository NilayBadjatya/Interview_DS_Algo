class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_p = find(x);
        int y_p = find(y);
        if (x_p != y_p) {
            if (rank[x_p] > rank[y_p]) {
                parent[y_p] = x_p;
            } else if (rank[y_p] > rank[x_p]) {
                parent[x_p] = y_p;
            } else {
                parent[x_p] = y_p;
                rank[y_p]++;
            }
        }
    }

    // int dfs(unordered_map<int, vector<vector<int>>>& adj, int i, vector<bool>& visited){
    //     visited[i] = true;
    //     int maxi = 0;
    //     for(auto& v : adj[i]){
    //         if(!visited[v[0]]){
    //             maxi = max(maxi, max(v[1], dfs(adj, v[0], visited)));
    //         }
    //     }
    //     return maxi;
    // }

    int isValid(int n, vector<vector<int>>& edges, int mid, int k) {
        int sz = edges.size();
        parent.resize(n);
        rank.resize(n, -1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        // unordered_map<int, vector<vector<int>>> adj;
        int comp = n, cost = 0;
        for(int i = mid+1; i < sz; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            // adj[u].push_back({v, w});
            // adj[v].push_back({u, w});
            int up = find(u);
            int vp = find(v);
            if(up != vp){
                Union(u, v);
                comp--;
                cost = max(cost, w);
            }
        }
        if(comp > k) return -1;
        return cost;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(),
             [&](vector<int>& a, vector<int>& b) { return a[2] > b[2]; });
        int sz = edges.size();
        int l = -1, r = sz - 1, ans = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int x = isValid(n, edges, mid, k);
            if (x != -1) {
                ans = min(ans, x);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
