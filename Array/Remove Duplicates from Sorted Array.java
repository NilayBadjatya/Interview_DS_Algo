class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int i = 0, j = 0, k = 0;
        while(i < n){
            while(j < n && nums[j] == nums[i]){
                j++;
            }
            nums[k] = nums[i];
            k++;
            i = j;
        }
        return k;
    }
}
