class Solution {
public:

    void solve(vector<int>& nums, int i, int sum, int target, vector<int> temp, vector<vector<int>>& list){
        if(sum > target || i == nums.size()) return;
        if(sum == target){
            sort(temp.begin(), temp.end());
            if(find(list.begin(), list.end(), temp) == list.end())
                list.push_back(temp);
            return;
        }
        for(int j = i; j < nums.size(); j++){
            sum += nums[j];
            temp.push_back(nums[j]);
            solve(nums, i, sum, target, temp, list);
            temp.pop_back();
            sum -= nums[j];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> list;
        solve(nums, 0, 0, target, temp, list);
        return list;
    }
};
