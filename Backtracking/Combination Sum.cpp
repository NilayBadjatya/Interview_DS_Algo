class Solution {
public:

    void solve(vector<int>& nums, int i, int target, vector<int> temp, vector<vector<int>>& list){
        if(target < 0) return;
        if(target == 0){
            list.push_back(temp);
            return;
        }
        for(int j = i; j < nums.size(); j++){
            temp.push_back(nums[j]);
            solve(nums, j, target - nums[j], temp, list);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> list;
        solve(nums, 0, target, temp, list);
        return list;
    }
};
