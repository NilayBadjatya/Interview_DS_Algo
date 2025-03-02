class Solution {
public:

    int bS(vector<int>& nums, int l, int r, int target){
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return -1;
    }

    int bSP(vector<int>& nums, int l, int r){
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = -1;
        pivot = bSP(nums, 0, n-1);
        int x = bS(nums, 0, pivot-1, target);
        x = max(x, bS(nums, pivot, n-1, target));
        return x;
    }
};
