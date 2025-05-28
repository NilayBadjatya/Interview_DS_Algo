typedef pair<int, int> P;
class Solution {
public:

    vector<int> dijktras(unordered_map<int, vector<int>>& adj, int src, int n){
        vector<int> result(n, INT_MAX);
        result[src] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto& v : adj[node]){
                if(dis + 1 < result[v]){
                    result[v] = dis + 1;
                    pq.push({dis + 1, v});
                }
            }
        }
        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();
        vector<int> indegree(m+1, 0);
        for(auto& e : edges2){
            int u = e[0];
            int v = e[1];
            indegree[u]++;
            indegree[v]++;
        }
        int node = -1, maxIndegree = 0;
        for(int i = 0; i < m+1; i++){
            if(indegree[i] > maxIndegree){
                maxIndegree = indegree[i];
                node = i;
            }
        }
        // cout << node << endl;
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
        int maxCount = 0;
        for(int i = 0; i < m+1; i++){
            vector<int> minDis = dijktras(adj2, i, m+1);
            int cnt = 0;
            for(auto& x : minDis){
                if(x <= k-1){
                    cnt++;
                }
            }
            maxCount = max(maxCount, cnt);
        }
        vector<int> answer(n+1, maxCount);
        for(int i = 0; i < n+1; i++){
            vector<int> minDis2 = dijktras(adj1, i, n+1);
            int cnt = 0;
            for(auto& x : minDis2){
                // cout << x << " ";
                if(x <= k){
                    cnt++;
                }
            }
            // cout << endl;
            answer[i] += cnt;
        }
        return answer;
    }
};
