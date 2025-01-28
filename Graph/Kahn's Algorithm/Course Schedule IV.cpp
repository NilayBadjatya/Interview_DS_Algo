class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<int> indegree(n, 0);
        unordered_map<int, vector<int>> adj;
        for(auto &e : p){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> qu;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                qu.push(i);
            }
        }
        unordered_map<int, unordered_set<int>> mp;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            for(auto &v : adj[node]){
                mp[v].insert(node);
                for(auto &x : mp[node]){
                    mp[v].insert(x);
                }
                indegree[v]--;
                if(indegree[v] == 0){
                    qu.push(v);
                }
            }
        }
        vector<bool> res(q.size(), false);
        for(int i = 0; i < q.size(); i++){
            int u = q[i][0];
            int v = q[i][1];
            if(mp[v].count(u) != 0){
                res[i] = true;
            }
        }
        return res;
    }
};
