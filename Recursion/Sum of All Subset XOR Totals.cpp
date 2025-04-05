//C++ Code
class Solution {
public:

    int solve(vector<int>& nums, int i, int currentXOR){
        if(i == nums.size()){
            return currentXOR;
        }
        return solve(nums, i+1, currentXOR ^ nums[i]) + solve(nums, i+1, currentXOR);
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};

//JAVA Code
class Solution {

    private int solve(int[] nums, int i, int ans){
        if(i == nums.length){
            return ans;
        }
        return solve(nums, i+1, ans ^ nums[i]) + solve(nums, i+1, ans);
    }

    public int subsetXORSum(int[] nums) {
        return solve(nums, 0, 0);
    }
}
