class Solution {
public:

    void solve(vector<int>& nums, int i, int target, vector<int>& temp, vector<vector<int>>& list){
        if(target < 0) return;
        if(target == 0){
            list.push_back(temp);
            return;
        }
        for(int j = i; j < nums.size(); j++){
            if(j > i && nums[j] == nums[j-1]) continue;
            temp.push_back(nums[j]);
            solve(nums, j+1, target - nums[j], temp, list);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> list;
        sort(nums.begin(), nums.end());
        solve(nums, 0, target, temp, list);
        return list;
    }
};
