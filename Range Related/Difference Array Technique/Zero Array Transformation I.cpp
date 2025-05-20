class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n, 0);
        for(auto& q : queries){
            int s = q[0];
            int e = q[1] + 1;
            diff[s]++;
            if(e < n){
                diff[e]--;
            }
        }
        for(int i = 1; i < n; i++){
            diff[i] += diff[i-1];
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > diff[i]){
                return false;
            }
        }
        return true;
    }
};
