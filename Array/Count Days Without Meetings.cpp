class Solution {
public:
    int countDays(int days, vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp = {nums[0][0], nums[0][1]};
        vector<vector<int>> merged;
        for(int i = 1; i < n; i++){
            if(nums[i][0] <= temp[1]){
                temp[0] = min(temp[0], nums[i][0]);
                temp[1] = max(temp[1], nums[i][1]);
            }else{
                merged.push_back(temp);
                temp[0] = nums[i][0];
                temp[1] = nums[i][1];
            }
        }
        merged.push_back(temp);
        for(int i = 0; i < merged.size(); i++){
            days -= (merged[i][1] - merged[i][0] + 1);
        }
        return days;
    }
};
