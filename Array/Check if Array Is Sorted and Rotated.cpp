class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> a = nums;
        sort(a.begin(), a.end());
        for (int j = 0; j < n; j++) {
            bool flag = true;
            int k = j;
            for (int i = 0; i < n; i++) {
                if (a[i] != nums[k]) {
                    flag = false;
                    break;
                }
                k = (k+1) % n;
            }
            if(flag) return true;
        }
        return false;
    }
};
