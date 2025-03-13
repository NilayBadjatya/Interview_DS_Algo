//Time Complexity - O(LogM * (M+N))
class Solution {
public:
    int n, m;
    bool checkWithDiff(vector<int>& nums, vector<vector<int>>& q, int mid){
        vector<int> diff(n, 0);
        for(int i = 0; i <= mid; i++){
            int l = q[i][0];
            int r = q[i][1];
            int val = q[i][2];
            diff[l] += val;
            if(r + 1 < n){
                diff[r+1] -= val;
            }
        }
        int currSum = 0;
        for(int i = 0; i < n; i++){
            currSum += diff[i];
            diff[i] = currSum;
            if(nums[i] - diff[i] > 0){
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        m = queries.size();
        auto lambda = [&](int x){
            return x == 0;
        };
        if(all_of(nums.begin(), nums.end(), lambda)){
            return 0;
        }
        int l = 0, r = m-1, ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(checkWithDiff(nums, queries, mid)){
                ans = mid+1;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
