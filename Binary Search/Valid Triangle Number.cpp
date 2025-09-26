class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        if(n < 3) return 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int thirdSide = nums[i] + nums[j];
                int idx = lower_bound(nums.begin(), nums.end(), thirdSide) - nums.begin();
                if(idx - j - 1 > 0)
                    ans += idx - j - 1;
            }
        }
        return ans;
    }
};

// JAVA CODE

class Solution {

    public int lower_bound(int[] nums, int k){
        int n = nums.length;
        int low = 0, high = n-1, idx = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] < k){
                idx = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return idx;
    }

    public int triangleNumber(int[] nums) {
        int n = nums.length, ans = 0;
        Arrays.sort(nums);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int thirdSide = nums[i] + nums[j];
                int idx = lower_bound(nums, thirdSide);
                ans += Math.max(idx - j, 0);
            }
        }
        return ans;
    }
}
