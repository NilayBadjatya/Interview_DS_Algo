//Time Complexity - O(N∗M∗Log(M)+N∗Log(N))
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            sort(grid[i].begin(), grid[i].end());
        }
        vector<int> ele;
        for(int i = 0; i < n; i++){
            int l = limits[i];
            int j = m-1;
            while(l--){
                ele.push_back(grid[i][j]);
                j--;
            }
        }
        sort(ele.begin(), ele.end());
        int i = ele.size() - 1;
        long long sum = 0;
        while(k--){
            sum += ele[i];
            i--;
        }
        return sum;
    }
};
