class Solution {
public:

    void dfs(unordered_map<int, vector<int>>& adj, int i, int p, vector<int>& inTime, vector<int>& outTime, vector<int>& nums, vector<int>& subtreeXor, int& timer){
        subtreeXor[i] = nums[i];
        inTime[i] = timer;
        timer++;
        for(auto& v : adj[i]){
            if(v == p) continue;
            dfs(adj, v, i, inTime, outTime, nums, subtreeXor, timer);
            subtreeXor[i] ^= subtreeXor[v];
        }
        outTime[i] = timer;
        timer++;
    }

    bool isAncestor(int u, int v, vector<int>& inTime, vector<int>& outTime){
        return inTime[u] <= inTime[v] && outTime[u] >= outTime[v];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        unordered_map<int, vector<int>> adj;

        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int timer = 0;
        vector<int> inTime(n, 0), outTime(n, 0);
        vector<int> subtreeXor(n, 0);
        dfs(adj, 0, -1, inTime, outTime, nums, subtreeXor, timer);

        int result = INT_MAX;
        for(int u = 1; u < n; u++){
            for(int v = u+1; v < n; v++){
                int xor1, xor2, xor3;
                if(isAncestor(u, v, inTime, outTime)){
                    xor1 = subtreeXor[v];
                    xor2 = subtreeXor[u] ^ xor1;
                    xor3 = subtreeXor[0] ^ subtreeXor[u];
                }else if(isAncestor(v, u, inTime, outTime)){
                    xor1 = subtreeXor[u];
                    xor2 = subtreeXor[v] ^ xor1;
                    xor3 = subtreeXor[0] ^ subtreeXor[v];
                }else{
                    xor1 = subtreeXor[v];
                    xor2 = subtreeXor[u];
                    xor3 = subtreeXor[0] ^ xor1 ^ xor2;
                }
                result = min(result, max({xor1, xor2, xor3}) - min({xor1, xor2, xor3}));
            }
        }
        return result;
    }
};
