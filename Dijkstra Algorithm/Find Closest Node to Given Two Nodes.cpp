typedef pair<int, int> P;
class Solution {
public:

    vector<int> dijktras(vector<int>& edges, int src, vector<bool>& vis, int n){
        vector<int> result(n, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;
        result[src] = 0;
        pq.push({0, src});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node] = true;
            int v = edges[node];
            if(v == -1) continue;
            if(!vis[v] && dis + 1 < result[v]){
                result[v] = dis + 1;
                pq.push({result[v], v});
            }
        }
        return result;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<bool> vis1(n, false), vis2(n, false);
        vector<int> dij1 = dijktras(edges, node1, vis1, n);
        vector<int> dij2 = dijktras(edges, node2, vis2, n);
        int minDis = INT_MAX, ansNode = -1;
        for(int i = 0; i < n; i++){
            if(dij1[i] == INT_MAX || dij2[i] == INT_MAX){
                continue;
            }else if(max(dij1[i], dij2[i]) < minDis){
                minDis = max(dij1[i], dij2[i]);
                ansNode = i;
            }
        }
        return ansNode;
    }
};
