class Solution {
public:

    int largestPathValue(string s, vector<vector<int>>& edges) {
        int n = s.size();
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n, 0);
        // Creating a adjacency list
        for(auto& x : edges){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        queue<int> q;
        vector<vector<int>> c(n, vector<int> (26, 0));
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
                c[i][s[i] - 'a'] = 1;
            }
        }
        int seen = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            seen++;
            for(auto& v : adj[node]){
                inDegree[v]--;
                for(int i = 0; i < 26; i++){
                    c[v][i] = max(c[v][i], c[node][i] + (i == s[v] - 'a'));
                }
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, *max_element(c[i].begin(), c[i].end()));
        }
        return seen < n ? -1 : maxi;
    }
};
