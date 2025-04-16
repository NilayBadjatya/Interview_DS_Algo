typedef long long ll;
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        ll i = 0, j = 0, ans = 0, pairs = 0;
        unordered_map<int, int> mp;
        while(j < n){
            int ele = nums[j];
            if(mp[ele] > 0){
                pairs += mp[ele];
            }
            mp[ele]++;
            while(pairs >= k){
                ans += n - j;
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                if(mp[nums[i]] > 0){
                    pairs -= mp[nums[i]];
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
