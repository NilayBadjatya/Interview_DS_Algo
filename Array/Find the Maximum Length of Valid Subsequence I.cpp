class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                even++;
            }else{
                odd++;
            }
        }
        int count10 = 0, count01 = 0;
        int toFind = 1;
        for(int i = 0; i < n; i++){
            if(toFind == (nums[i] % 2)){
                count10++;
                toFind = 1 - toFind;
            }
        }
        toFind = 0;
        for(int i = 0; i < n; i++){
            if(toFind == (nums[i] % 2)){
                count01++;
                toFind = 1 - toFind;
            }
        }
        return max({count10, count01, even, odd});
    }
};
