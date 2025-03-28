typedef pair<int, pair<int, int>> P;
class Solution {
public:

    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int size = queries.size();
        vector<vector<int>> a;
        for(int i = 0; i < size; i++){
            a.push_back({queries[i], i});
        }
        sort(a.begin(), a.end());
        vector<int> answer(size, 0);
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({grid[0][0], {0,0}});
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int i = 0; i < size; i++){
            int val = a[i][0];
            int idx = a[i][1];
            int count = 0;
            while(!pq.empty() && val > pq.top().first){
                int v = pq.top().first;
                int i = pq.top().second.first;
                int j = pq.top().second.second;
                pq.pop();
                if(visited[i][j]) continue;
                visited[i][j] = true;
                for(auto& d : dir){
                    int ii = i + d[0];
                    int jj = j + d[1];
                    if(isValid(ii, jj, m, n)){
                        pq.push({grid[ii][jj], {ii, jj}});
                    }
                }
                count++;
            }
            answer[idx] = count;
            if(i > 0){
                answer[idx] += answer[a[i-1][1]];
            }
        }
        return answer;
    }
};
