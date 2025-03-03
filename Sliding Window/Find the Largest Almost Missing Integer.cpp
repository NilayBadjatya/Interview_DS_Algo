class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        int ans = -1;
        while(j < n){
            if(j - i + 1 < k){
                j++;
            }else if(j - i + 1 == k){
                unordered_set<int> st;
                for(int k = i; k <= j; k++){
                    if(st.count(nums[k]) == 0){
                        mp[nums[k]]++;
                        st.insert(nums[k]);
                    }
                }
                i++;
                j++;
            }
        }
        for(auto &x : mp){
            if(x.second == 1){
                ans = max(ans, x.first);
            }
        }
        return ans;
    }
};
