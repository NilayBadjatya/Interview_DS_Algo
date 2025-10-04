class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] newArr = new int[n];

        newArr[0] = nums[0];
        for(int i = 1; i < n; i++){
            newArr[i] = newArr[i-1] * nums[i];
        }

        int postfix = 1;
        for(int i = n-1; i >= 0; i--){
            if(i == 0){
                newArr[i] = postfix;
            }else{
                newArr[i] = postfix * newArr[i-1];
            }
            postfix *= nums[i];
        }
        return newArr;
    }
}
