class Solution {
  public:
    vector<int> largestSubset(vector<int>& nums) {
        // Code here
        
        int n = nums.size(), maxi = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        
        int maxiIdx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                        if(dp[i] > maxi){
                            maxi = dp[i];
                            maxiIdx = i;
                        }
                    }
                }
            }
        }
        
        vector<int> ans;
        while(maxiIdx != -1){
            ans.push_back(nums[maxiIdx]);
            maxiIdx = parent[maxiIdx];
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
