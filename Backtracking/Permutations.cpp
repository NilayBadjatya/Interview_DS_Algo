class Solution {
public:
    void backTrack(vector<int>& nums, vector<int> templist,
                   vector<vector<int>>& ans) {
        if (templist.size() == nums.size()) {
            ans.push_back(templist);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (find(templist.begin(), templist.end(), nums[i]) ==
                templist.end()) {
                templist.push_back(nums[i]);
                backTrack(nums, templist, ans);
                templist.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> templist;
        vector<vector<int>> ans;
        backTrack(nums, templist, ans);
        return ans;
    }
};
