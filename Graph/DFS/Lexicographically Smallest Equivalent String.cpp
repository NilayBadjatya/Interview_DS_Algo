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

//--------------------------------JAVA----------------------------------

class Solution {

    void dfs(Map<Character, List<Character>> adj, char c, boolean[] visited){
        visited[c - 'a'] = true;
        for(char v : adj.getOrDefault(c, new ArrayList<>())){
            if(!visited[v - 'a']){
                dfs(adj, v, visited);
            }
        }
    }

    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        int n = s1.length();
        int m = baseStr.length();

        Map<Character, List<Character>> adj = new HashMap<>();
        for(int i = 0; i < n; i++){
            char a = s1.charAt(i);
            char b = s2.charAt(i);

            adj.computeIfAbsent(a, k -> new ArrayList<>()).add(b);
            adj.computeIfAbsent(b, k -> new ArrayList<>()).add(a);
        }

        String res = "";
        for(int i = 0; i < m; i++){
            boolean[] visited = new boolean[26];
            dfs(adj, baseStr.charAt(i), visited);
            char c = baseStr.charAt(i);
            for(int j = 0; j < 26; j++){
                if(visited[j]){
                    c = (char)(j + 'a');
                    break;
                }
            }
            if(c < baseStr.charAt(i)){
                res += c;
            }else{
                res += baseStr.charAt(i);
            }
        }
        return res;
    }
}
