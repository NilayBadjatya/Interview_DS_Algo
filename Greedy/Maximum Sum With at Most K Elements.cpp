class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> a;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a.push_back({grid[i][j], i});
            }
        }
        sort(a.begin(), a.end(), greater<pair<int, int>>());

        long long sum = 0;
        for(int i = 0; i < a.size() && k > 0; i++){
            int idx = a[i].second;
            if(limits[idx] > 0){
                sum += a[i].first;
                limits[idx]--;
                k--;
            }
        }
        return sum;
    }
};
