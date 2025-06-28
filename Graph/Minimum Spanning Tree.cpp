// Prim's Algorithm
Time Complexity - O(ELogE)
typedef vector<int> P;
class Solution {
  public:
    int spanningTree(int n, vector<vector<int>> adj[]) {
        // code here
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);
        pq.push({0, 0, -1});
        int sum = 0;
        while(!pq.empty()){
            int wt = pq.top()[0];
            int node = pq.top()[1];
            int p = pq.top()[2];
            pq.pop();
            if(visited[node]) continue;
            visited[node] = true;
            parent[node] = p;
            sum += wt;
            for(auto& v : adj[node]){
                if(!visited[v[0]]){
                    pq.push({v[1], v[0], node});
                }
            }
        }
        return sum;
    }
};

// Kruskal's Algorithm
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<int> parent;
    vector<int> rank;
    
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(rank[x] > rank[y]){
            parent[y] = x;
        }else if(rank[y] > rank[x]){
            parent[x] = y;
        }else{
            parent[x] = y;
            rank[y]++;
        }
    }
    
    int Kruskal(vector<vector<int>>& vec, int n){
        int sum = 0;
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            rank[i] = 0;
            parent[i] = i;
        }
        for(auto& t : vec){
            int u = t[1];
            int v = t[2];
            int wt = t[0];
            int up = find(u);
            int vp = find(v);
            if(up != vp){
                Union(u, v);
                sum += wt;
            }
        }
        return sum;
    }
    
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<vector<int>> vec;
        for(int i = 0; i < V; i++){
            for(auto& v : adj[i]){
                vec.push_back({v[1], i, v[0]});
            }
        }
        sort(vec.begin(), vec.end());
        return Kruskal(vec, V);
    }
};
