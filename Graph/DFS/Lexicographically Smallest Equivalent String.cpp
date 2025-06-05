class Solution {
public:

    void dfs(unordered_map<char, vector<char>>& adj, char c, vector<bool>& visited){
        visited[c - 'a'] = true;
        for(auto& v : adj[c]){
            if(!visited[v - 'a']){
                dfs(adj, v, visited);
            }
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int m = baseStr.size();

        unordered_map<char, vector<char>> adj;
        for(int i = 0; i < n; i++){
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }

        string res = "";
        for(int i = 0; i < m; i++){
            vector<bool> visited(26, false);
            dfs(adj, baseStr[i], visited);
            char c;
            for(int i = 0; i < 26; i++){
                if(visited[i]){
                    c = (i + 'a');
                    break;
                }
            }
            if(c < baseStr[i]){
                res += c;
            }else{
                res += baseStr[i];
            }
        }
        return res;
    }
};
