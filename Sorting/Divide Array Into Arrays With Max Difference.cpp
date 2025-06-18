class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> a;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i += 3){
            int idx = i + 2;
            if(nums[idx] - nums[i] > k){
                // cout << idx << " " << nums[idx] - nums[i];
                return {};
            }
            a.push_back({nums[i], nums[i+1], nums[idx]});
        }

        return a;
    }
};
