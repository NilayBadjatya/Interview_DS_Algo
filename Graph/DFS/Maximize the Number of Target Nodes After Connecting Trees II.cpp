class Solution {
public:

    void dfs(unordered_map<int, vector<int>>& adj, int node, vector<int>& color, int curr){
        color[node] = curr;
        for(auto& v : adj[node]){
            if(color[v] == -1){
                dfs(adj, v, color, 1 - color[node]);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();
        unordered_map<int, vector<int>> adj1, adj2;
        for(auto& e : edges1){
            int u = e[0];
            int v = e[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto& e : edges2){
            int u = e[0];
            int v = e[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        vector<int> color1(n+1, -1), color2(m+1, -1);
        dfs(adj1, 0, color1, 0);
        dfs(adj2, 0, color2, 0);
        int maxiTree2 = 0, white = 0, black = 0;
        for(auto& c : color2){
            if(c == 0){
                white++;
            }else{
                black++;
            }
        }
        maxiTree2 = max(white, black);
        vector<int> answer(n+1, 0);
        white = 0, black = 0;
        for(auto& c : color1){
            if(c == 0){
                white++;
            }else{
                black++;
            }
        }
        for(int i = 0; i < n+1; i++){
            if(color1[i] == 0){
                answer[i] = maxiTree2 + white;
            }else{
                answer[i] = maxiTree2 + black;
            }
        }
        return answer;
    }
};
