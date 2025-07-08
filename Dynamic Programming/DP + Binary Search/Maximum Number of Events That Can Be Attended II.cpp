class Solution {
public:
    int binarySearch(vector<vector<int>>& events, int i){
        int l = i+1, r = events.size()-1, ans = events.size();
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(events[mid][0] > events[i][1]){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }

    int solve(vector<vector<int>>& events, int i, int k, vector<vector<int>>& dp){
        if(k == 0){
            return 0;
        }
        if(i == events.size()){
            return 0;
        }
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        int nextIdx = binarySearch(events, i);
        int take = events[i][2] + solve(events, nextIdx, k-1, dp);
        int skip = solve(events, i+1, k, dp);
        return dp[i][k] = max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
        return solve(events, 0, k, dp);
    }
};
