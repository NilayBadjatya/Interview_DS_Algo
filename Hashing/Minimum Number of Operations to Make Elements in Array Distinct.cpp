//C++ Code
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(101, 0);
        for(int i = n-1; i >= 0; i--){
            if(f[nums[i]] > 0){
                return ceil((i+1) / (3 * 1.0));
            }
            f[nums[i]]++;
        }
        return 0;
    }
};

//Java Code
class Solution {
    public int minimumOperations(int[] nums) {
        int n = nums.length;
        int[] f = new int[101];
        Arrays.fill(f, 0);
        for(int i = n-1; i >= 0; i--){
            if(f[nums[i]] > 0){
                return (int)Math.ceil((i+1) / (3 * 1.0));
            }
            f[nums[i]]++;
        }
        return 0;
    }
}
