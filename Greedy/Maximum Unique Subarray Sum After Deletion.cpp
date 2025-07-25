class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        bool allNegative = true;
        for(auto& x : nums){
            mp[x]++;
            if(x >= 0){
                allNegative = false;
            }
        }

        if(allNegative){
            return *max_element(nums.begin(), nums.end());
        }

        int sum = 0;
        unordered_set<int> st;

        for(auto& x : mp){
            int ele = x.first;
            if(ele >= 0 && st.count(ele) == 0){
                sum += ele;
            }
        }
        return sum;
    }
};
