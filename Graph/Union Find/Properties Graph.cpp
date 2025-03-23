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
    int numberOfComponents(vector<vector<int>>& q, int k) {
        int n = q.size();
        vector<vector<int>> edges;
        for(int i = 0; i < n; i++){
            vector<int> v = q[i];
            unordered_set<int> st(v.begin(), v.end());
            for(int j = i+1; j < n; j++){
                int count = 0;
                vector<int> v2 = q[j];
                unordered_set<int> st2;
                for(auto &x : v2){
                    if(st.count(x) != 0 && st2.count(x) == 0){
                        count++;
                        st2.insert(x);
                    }
                }
                if(count >= k){
                    edges.push_back({i, j});
                }
            }
        }
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = -1;
        }
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int up = find(u);
            int vp = find(v);
            if(up != vp){
                Union(u, v);
            }
        }
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int x = find(i);
            mp[x]++;
        }
        return (int)mp.size();
    }
};
