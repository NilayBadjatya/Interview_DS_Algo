class Solution {
public:

    void dfs(int node, int parent, int d, unordered_map<int, vector<int>>& adj, vector<vector<int>>& up, vector<int>& depth){
        depth[node] = d;
        up[0][node] = parent;
        for(auto& v : adj[node]){
            if(v == parent) continue;
            dfs(v, node, d+1, adj, up, depth);
        }
    }

    void inititalizationOfUpTable(vector<vector<int>>& up, int maxBit, int n){
        for(int i = 1; i < maxBit; i++){
            for(int j = 0; j < n; j++){
                if(up[i-1][j] == -1) continue;
                up[i][j] = up[i-1][up[i-1][j]];
            }
        }
    }

    int findLCA(int u, int v, vector<vector<int>>& up, int maxBit, vector<int>& depth){
        if(depth[u] < depth[v]){
            swap(u, v);
        }
        int d = depth[u] - depth[v];
        // Lifting up u upto the same level as of v
        for(int i = 0 ; i < maxBit; i++){
            if((d >> i) & 1){
                u = up[i][u];
            }
        }
        if(u == v){
            return u;
        }
        // Lifting both u and v till their parents diverge
        for(int i = maxBit-1; i >= 0; i--){
            if(up[i][u] != up[i][v]){
                u = up[i][u];
                v = up[i][v];
            }
        }
        return up[0][u];
    }

    int getDistance(int u, int v, vector<int>& depth, vector<vector<int>>& up, int maxBit){
        int lca = findLCA(u, v, up, maxBit, depth);
        return depth[u] + depth[v] - 2 * depth[lca];
    }

    int MOD = 1e9 + 7;
    int findPower(int a, int b){
        if(b == 0){
            return 1;
        }
        long long half = findPower(a, b/2);
        long long result = (half * half) % MOD;
        if(b % 2 != 0){
            result = (result * a) % MOD;
        } 
        return result;
    }
    
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>&queries) {
        int n = edges.size() + 1;
        int m = queries.size();
        unordered_map<int, vector<int>> adj;
        for(auto& e : edges){
            int u = e[0]-1;
            int v = e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maxBit = log2(n) + 1;
        vector<int> depth(n);// root se distance baaki nodes ka
        vector<vector<int>> up(maxBit, vector<int> (n, -1));// Binary lifting ke help se LCA find karenge efficiently

        dfs(0, -1, 0, adj, up, depth);

        inititalizationOfUpTable(up, maxBit, n);
        
        vector<int> answer(m);
        for(int i = 0; i < m; i++){
            int u = queries[i][0]-1;
            int v = queries[i][1]-1;
            int dist = getDistance(u, v, depth, up, maxBit);
            if(dist == 0){
                answer[i] = 0;
                continue;
            }
            answer[i] = findPower(2, dist-1);
        }
        return answer;
    }
};
