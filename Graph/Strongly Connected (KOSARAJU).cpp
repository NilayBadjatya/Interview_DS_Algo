//Position this line where user code will be pasted.
class Solution {
  public:
  
    void dfsFill(vector<vector<int>> &adj, int i, stack<int>& st, vector<bool>& visited){
        visited[i] = true;
        for(auto& v : adj[i]){
            if(!visited[v]){
                dfsFill(adj, v, st, visited);
            }
        }
        st.push(i);
    }
    
    void dfs(vector<vector<int>> &adjRev, int i, vector<bool>& visited){
        visited[i] = true;
        for(auto& v : adjRev[i]){
            if(!visited[v]){
                dfs(adjRev, v, visited);
            }
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        stack<int> st;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfsFill(adj, i, st, visited);
            }
        }
        
        vector<vector<int>> adjRev(n);
        for(int i = 0; i < n; i++){
            for(auto& v : adj[i]){
                adjRev[v].push_back(i);
            }
        }
        
        int countSCC = 0;
        visited = vector<bool>(n, false);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]){
                dfs(adjRev, node, visited);
                countSCC++;
            }
        }
        return countSCC;
    }
};
