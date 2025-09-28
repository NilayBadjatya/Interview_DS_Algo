class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int i = 0, j = 0, k = 0;
        while(i < n){
            int c = 0;
            while(c < 2 && j < n && nums[i] == nums[j]){
                nums[k] = nums[j];
                j++;
                k++;
                c++;
            }

            while(j < n && nums[i] == nums[j]){
                j++;
            }

            i = j;
        }
        return k;
    }
}
