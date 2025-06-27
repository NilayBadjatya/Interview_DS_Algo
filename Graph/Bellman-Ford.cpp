// TIme Complexity - O(E * V)
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> result(V, 1e8);
        result[src] = 0;
        for(int i = 0; i < V-1; i++){
            for(auto& e : edges){
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if(result[u] != 1e8 && result[u] + w < result[v]){
                    result[v] = result[u] + w;
                }
            }
        }
        for(auto& e : edges){
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if(result[u] != 1e8 && result[u] + w < result[v]){
                    return {-1};
                }
            }
        return result;
    }
};
