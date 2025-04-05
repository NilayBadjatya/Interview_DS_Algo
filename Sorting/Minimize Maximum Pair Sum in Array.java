class Solution {
    public int minPairSum(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int pairSum = 0;
        int i = 0, j = n-1;
        while(i < j){
            pairSum = Math.max(pairSum, nums[i++]+nums[j--]);
        }
        return pairSum;
    }
}
