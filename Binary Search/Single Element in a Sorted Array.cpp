class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((mid == 0 || nums[mid] != nums[mid - 1]) &&
                (mid == n - 1 || nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }
            if (mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
                if ((mid - 1) % 2 == 0) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else if (mid + 1 < n && nums[mid + 1] == nums[mid]) {
                if (mid % 2 == 0) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
