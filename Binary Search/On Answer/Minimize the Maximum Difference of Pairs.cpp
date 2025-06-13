class Solution {
public:

    bool isValid(vector<int>& nums, int mid, int p){
        int n = nums.size();

        for(int i = 0; i < n-1; i++){
            int diff = abs(nums[i] - nums[i+1]);
            if(diff <= mid){
                p--;
                i++;
            }
        }

        return p <= 0;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, r = nums[n-1] - nums[0], ans = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(isValid(nums, mid, p)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};
