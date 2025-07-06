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

    bool isValid(int c, vector<vector<int>>& edges, int mid, int k){
        for (int i = 0; i < c; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int time = e[2];
            if(time > mid){
                Union(u, v);
            }
        }
        unordered_map<int, int> mp;
        for(int i = 0; i < c; i++){
            int p = find(i);
            mp[p]++;
        }
        int components = mp.size();
        return components >= k;
    }

    int minTime(int c, vector<vector<int>>& edges, int k) {
        vector<int> times(edges.size());
        parent.resize(c);
        rank.resize(c, 1);
        for(auto& e : edges){
            times.push_back(e[2]);
        }
        sort(times.begin(), times.end());
        int n = times.size();
        int l = 0, r = n-1, ans = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(isValid(c, edges, times[mid], k)){
                ans = times[mid];
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
