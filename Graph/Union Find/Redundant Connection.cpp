class Solution {
public:
    vector<int> parent, rank;
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int xp = find(x);
        int yp = find(y);
        if(rank[xp] > rank[yp]){
            parent[yp] = xp;
        }else if(rank[yp] > rank[xp]){
            parent[xp] = yp;
        }else{
            parent[xp] = yp;
            rank[yp]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i = n-1; i >= 0; i--){
            parent.resize(n);
            rank.resize(n, -1);
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                Union(edges[j][0]-1, edges[j][1]-1);
            }
            bool istrue = true;
            for(int i = 1; i < n; i++){
                if(find(i) != find(i-1)){
                    istrue = false;
                    break;
                }
            }
            if(istrue){
                return edges[i];
            }
        }
        return {};
    }
};
