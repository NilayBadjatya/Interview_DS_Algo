class Solution {
public:
    int dp[105][105];
    int solve(vector<int>& cuts, int i, int j) {
        if (i+1 >= j) {
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int cost = INT_MAX;
        for (int k = i+1; k < j; k++) {
            cost = min(cost, cuts[j] - cuts[i] + solve(cuts, i, k) +
                                 solve(cuts, k, j));
        }
        return dp[i][j] = cost;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof(dp));
        return solve(cuts, 0, cuts.size() - 1);
    }
};
