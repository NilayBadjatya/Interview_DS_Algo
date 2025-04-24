class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int k = st.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0, n = nums.size(), ans = 0;
        while(j < n){
            mp[nums[j]]++;
            while(mp.size() >= k){
                ans += n - j;
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }   
        return ans;
    }
};
