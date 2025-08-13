class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) return 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            if(nums[i] != i){
                st.insert(nums[i]);
            }
        }

        vector<int> a;
        for(auto& x : st){
            a.push_back(x);
        }

        int val = a[0];
        for(int i = 1; i < a.size(); i++){
            val &= a[i];
        }
        return val;
    }
};
