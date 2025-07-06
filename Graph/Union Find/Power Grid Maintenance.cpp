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

    vector<int> processQueries(int c, vector<vector<int>>& edges,
                               vector<vector<int>>& q) {
        unordered_map<int, vector<int>> adj;
        parent.resize(c);
        rank.resize(c, 1);
        for(int i = 0; i < c; i++){
            parent[i] = i;
        }
        for (auto& e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
            Union(u, v);
        }
        unordered_map<int, set<int>> mp;
        for(int i = 0; i < c; i++){
            int p = find(i);
            mp[p].insert(i);
        }
        vector<int> isOnline(c, true);
        vector<int> ans;
        for (int i = 0; i < q.size(); i++) {
            int type = q[i][0];
            int node = q[i][1] - 1;
            if (type == 2) {
                isOnline[node] = false;
                int p = find(node);
                mp[p].erase(node);
                continue;
            }
            if (isOnline[node]) {
                ans.push_back(node+1);
            } else {
                int p = find(node);
                if(mp[p].size() == 0){
                    ans.push_back(-1);
                }else{
                    ans.push_back(*mp[p].begin() + 1);
                }
            }
        }
        return ans;
    }
};
