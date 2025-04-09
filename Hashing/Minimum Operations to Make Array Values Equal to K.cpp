//Java Code
class Solution {
    public int minOperations(int[] nums, int k) {
        Set<Integer> st = new HashSet<>();
        for(int x : nums){
            if(x < k) return -1;
            if(x > k)
            st.add(x);
        }
        return (int)st.size();
    }
}

//C++ Code
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(k > nums[0]){
            return -1;
        }
        int ops = 0;
        vector<int> f(101, 0);
        for(int i = n-1; i >= 0; i--){
            if(nums[i] > k && f[nums[i]] == 0){
                ops++;
                f[nums[i]]++;
            }else if(nums[i] <= k){
                break;
            }
        }
        return ops;
    }
};
