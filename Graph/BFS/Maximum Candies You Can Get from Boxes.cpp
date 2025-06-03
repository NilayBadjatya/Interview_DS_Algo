class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = status.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            for (auto& x : containedBoxes[i]) {
                adj[i].push_back(x);
            }
        }
        queue<int> q;
        vector<bool> visited(n, false);
        for (auto& x : initialBoxes) {
            q.push(x);
        }
        unordered_set<int> prev;
        int ans = 0;
        while (!q.empty()) {
            int box = q.front();
            q.pop();
            if(visited[box]) continue;
            if(status[box] == 0){
                prev.insert(box);
                continue;
            }
            visited[box] = true;
            ans += candies[box];
            for(auto& k : keys[box]){
                status[k] = 1;
            }
            for(auto& v : adj[box]){
                if(status[v]){
                    q.push(v);
                }else{
                    prev.insert(v);
                }
            }
            for(auto& x : prev){
                if(status[x]){
                    q.push(x);
                }
            }
        }
        return ans;
    }
};
