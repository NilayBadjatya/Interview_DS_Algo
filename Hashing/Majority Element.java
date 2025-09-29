class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int ele = -1, cnt = 0;
        for(int i = 0; i < n; i++){
            if(cnt == 0){
                ele = nums[i];
                cnt++;
            }else if(ele == nums[i]){
                cnt++;
            }else{
                cnt--;
            }
        }

        int freq = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == ele){
                freq++;
            }
        }

        if(freq > n/2) return ele;
        return -1;
    }
}
