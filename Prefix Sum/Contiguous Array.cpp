class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0] == 1 ? 1 : -1;
        for(int i = 1; i < n; i++){
            if(nums[i] == 0){
                prefix[i] = prefix[i-1] - 1;
            }else{
                prefix[i] = prefix[i-1] + 1;
            }
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(mp.count(prefix[i]) != 0){
                ans = max(ans, i - mp[prefix[i]]);
            }else{
                mp[prefix[i]] = i;
            }
        }
        return ans;
    }
};
