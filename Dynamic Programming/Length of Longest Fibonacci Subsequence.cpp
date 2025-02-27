//Approach 1 : Recursion
// Time Complexity - O(N^2)
class Solution {
public:

    int solve(int j, int k, vector<int>& nums, unordered_map<int, int>& mp){
        int target = nums[k] - nums[j];
        if(mp.count(target) && mp[target] < j){
            return 1 + solve(mp[target], j, nums, mp);
        }
        return 2;
    }

    int lenLongestFibSubseq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]] = i;
        }
        int res = 0;
        for(int j = 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int length = solve(j, k, nums, mp);
                if(length >= 3){
                    res = max(res, length);
                }
            }
        }
        return res;
    }
};

// Approach 2: Top Down DP
class Solution {
public:
    int dp[1001][1001];
    int solve(int j, int k, vector<int>& nums, unordered_map<int, int>& mp){
        int target = nums[k] - nums[j];
        if(dp[j][k] != -1){
            return dp[j][k];
        }
        if(mp.count(target) && mp[target] < j){
            return dp[j][k] = 1 + solve(mp[target], j, nums, mp);
        }
        return dp[j][k] = 2;
    }

    int lenLongestFibSubseq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]] = i;
        }
        int res = 0;
        memset(dp, -1,sizeof(dp));
        for(int j = 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int length = solve(j, k, nums, mp);
                if(length >= 3){
                    res = max(res, length);
                }
            }
        }
        return res;
    }
};
