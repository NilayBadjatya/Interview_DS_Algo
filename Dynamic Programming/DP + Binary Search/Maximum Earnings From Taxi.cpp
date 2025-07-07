class Solution {
public:
    long long solve(vector<vector<int>>& rides, int i, vector<long long>& dp){
        if(i == rides.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int nextIdx = binarySearch(rides, i);
        long long take = rides[i][1] - rides[i][0] + rides[i][2] + solve(rides, nextIdx, dp);
        long long skip = solve(rides, i+1, dp);
        return dp[i] = max(take, skip);
    }

    int binarySearch(vector<vector<int>>& rides, int i){
        int l = i+1, r = rides.size() - 1, ans = rides.size();
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(rides[mid][0] >= rides[i][1]){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m = rides.size();
        sort(rides.begin(), rides.end());
        vector<long long> dp(m+1, -1);
        return solve(rides, 0, dp);
    }
};
