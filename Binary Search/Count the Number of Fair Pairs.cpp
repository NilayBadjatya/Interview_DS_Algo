class Solution {
public:

    int findLowerBoundIdx(vector<int>& nums, int l, int r, int lower, int curr){
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] + curr >= lower){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }

    int findUpperBoundIdx(vector<int>& nums, int l, int r, int upper, int curr){
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] + curr <= upper){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long l_idx = findLowerBoundIdx(nums, i+1, n-1, lower, nums[i]);
            long long u_idx = findUpperBoundIdx(nums, i+1, n-1, upper, nums[i]);
            if(l_idx == -1 || u_idx == -1) continue;
            ans += u_idx - l_idx + 1;
        }
        return ans;
    }
};
