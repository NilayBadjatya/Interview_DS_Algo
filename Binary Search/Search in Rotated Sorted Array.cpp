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

// Another Version

class Solution {
public:

    int binarySearch(vector<int>& nums, int l, int r, int target){
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[0] > nums[mid]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        int pivot = r;
        int idx1 = binarySearch(nums, 0, pivot, target);
        int idx2 = binarySearch(nums, pivot+1, n-1, target);
        if(idx1 == -1 && idx2 == -1){
            return -1;
        }else if(idx1 == -1){
            return idx2;
        }
        return idx1;
    }
};
