class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> arr = new ArrayList<>();
        for(int i = 0; i < n; i++){
            int j = i + 1, k = n-1;
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    arr.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j++;
                    k--;
                    while(j < k && nums[k] == nums[k+1]){
                        k--;
                    }
                    while(j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                }else if(sum > 0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return arr;
    }
}
