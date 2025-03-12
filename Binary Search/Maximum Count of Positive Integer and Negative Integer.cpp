class Solution {
public:
    //Time Complexity - O(LogN)
    int binarySearchPositive(vector<int>& nums, int l, int r){
        int idx = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] <= 0){
                l = mid + 1;
            }else{
                idx = mid;
                r = mid-1;
            }
        }
        return idx;
    }

    int binarySearchNegative(vector<int>& nums, int l, int r){
        int idx = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < 0){
                idx = mid;
                l = mid + 1;
            }else{
                r = mid-1;
            }
        }
        return idx;
    }

    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int firstPosiIdx = binarySearchPositive(nums, 0, n-1);
        int lastNegaIdx = binarySearchNegative(nums, 0, n-1);
        if(firstPosiIdx == -1 && lastNegaIdx == -1){
            return 0;
        }else if(firstPosiIdx == -1){
            return lastNegaIdx + 1;
        }else if(lastNegaIdx == -1){
            return n - firstPosiIdx;
        }
        return max(lastNegaIdx + 1, n - firstPosiIdx);
    }
};
