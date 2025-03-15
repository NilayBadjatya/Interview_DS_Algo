//Time Complexity - O(N * LogN)
class Solution {
public:
    bool isValid(vector<int>& nums, int mid, int k) {
        int count = 0;
        unordered_set<int> posi;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= mid) {
                if (posi.count(i) == 0) {
                    count++;
                    posi.insert(i + 1);
                    posi.insert(i - 1);
                }
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size(), ans = -1;
        int l = *min_element(nums.begin(), nums.end()),
            r = *max_element(nums.begin(), nums.end());
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(nums, mid, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
