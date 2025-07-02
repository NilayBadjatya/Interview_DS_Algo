class Solution {
  public:
    int totalElements(vector<int> &nums) {
        int n = nums.size();
        int i = 0, j = 0, ans = INT_MIN;
        unordered_map<int, int> mp;
        while(j < n){
            mp[nums[j]]++;
            while(mp.size() > 2){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            if(mp.size() <= 2){
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        return ans;
    }
};
