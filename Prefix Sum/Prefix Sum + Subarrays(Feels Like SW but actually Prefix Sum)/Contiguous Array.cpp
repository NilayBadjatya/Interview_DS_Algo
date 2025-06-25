class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        if(nums[0] == 0){
            prefix[0] = -1;
        }else{
            prefix[0] = 1;
        }

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + (nums[i] == 1 ? 1 : -1);
        }

        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(mp.count(prefix[i])){
                ans = max(ans, i - mp[prefix[i]]);
            }else{
                mp[prefix[i]] = i;
            }
        }
        return ans;
    }
};
