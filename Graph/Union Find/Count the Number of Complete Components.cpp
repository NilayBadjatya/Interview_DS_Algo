class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int xp = find(x);
        int yp = find(y);
        if(xp != yp){
            if(rank[xp] > rank[yp]){
                parent[yp] = xp;
            }else if(rank[yp] > rank[xp]){
                parent[xp] = yp;
            }else{
                parent[xp] = yp;
                rank[yp]++;
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> adj;
        parent.resize(n);
        rank.resize(n, -1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int up = find(u);
            int vp = find(v);
            if(up != vp){
                Union(up, vp);
            }
        }
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            int x = find(i);
            mp[x].push_back(i);
        }
        int components = 0;
        for(auto& x : mp){
            bool allConnected = true;
            vector<int> v = x.second;
            for(int i = 0; i < v.size(); i++){
                for(int j = 0; j < v.size(); j++){
                    if(v[i] == v[j]) continue;
                    if(adj[v[i]].count(v[j]) == 0){
                        allConnected = false;
                        break;
                    }
                }
                if(!allConnected) break;
            }
            if(allConnected) components++;
        }
        return components;
    }
};
