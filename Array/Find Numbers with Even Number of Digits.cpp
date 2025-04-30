class Solution {
public:

    bool isValid(int x){
        int count = 0;
        while(x > 0){
            x /= 10;
            count++;
        }
        return count % 2 == 0;
    }

    int findNumbers(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for(int i = 0; i < n; i++){
            if(isValid(nums[i])){
                count++;
                // cout << i << " ";
            }
        }
        return count;
    }
};
