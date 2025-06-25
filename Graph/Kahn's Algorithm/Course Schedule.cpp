class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n, 0);
        for(auto& e : edges){
            int u = e[1];
            int v = e[0];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        int course = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            course++;
            for(auto& v : adj[node]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return course == n;
    }
};
