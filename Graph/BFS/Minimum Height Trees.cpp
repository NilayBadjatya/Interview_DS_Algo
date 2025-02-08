class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        if(n == 1){
            return {0};
        }
        vector<int> inDegree(n, 0);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            inDegree[u]++;
            inDegree[v]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 1){
                q.push(i);
            }
        }
        while(n > 2){
            int size = q.size();
            n -= size;
            while(size--){
                int node = q.front();
                q.pop();
                for(auto &v : adj[node]){
                    inDegree[v]--;
                    if(inDegree[v] == 1){
                        q.push(v);
                    }
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
