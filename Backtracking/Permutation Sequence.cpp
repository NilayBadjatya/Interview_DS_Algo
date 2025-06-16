class Solution {
public:
    void getAllPermutation(string s, string t, vector<string>& nums,
                           vector<int>& used) {
        if (t.size() == s.size()) {
            nums.push_back(t);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (used[i] == 0) {
                t += s[i];
                used[i] = 1;
                getAllPermutation(s, t, nums, used);
                t.pop_back();
                used[i] = 0;
            }
        }
    }

    string getPermutation(int n, int k) {
        string s = "";
        for (int i = 1; i <= n; i++) {
            s += (i + '0');
        }
        vector<string> nums;
        vector<int> used(n + 1, 0);
        getAllPermutation(s, "", nums, used);
        return nums[k - 1];
    }
};
