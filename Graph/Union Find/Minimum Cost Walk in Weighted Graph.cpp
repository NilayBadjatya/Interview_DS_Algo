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
        parent[yp] = xp;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        parent.resize(n);
        rank.resize(n);
        vector<int> cost(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            cost[i] = -1;
            rank[i] = 0;
        } 
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            int up = find(u);
            int vp = find(v);
            if(up != vp){
                Union(u, v);
                cost[up] &= cost[vp];
            }
            cost[up] &= w;
        }
        vector<int> ans(q.size(), -1);
        for(int i = 0; i < q.size(); i++){
            int u = q[i][0];
            int v = q[i][1];
            int up = find(u);
            int vp = find(v);
            if(u == v){
                ans[i] = 0;
            }else if(up == vp){
                ans[i] = cost[up];
            }
        }
        return ans;
    }
};
