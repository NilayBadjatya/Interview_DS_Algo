class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size(), result = 0;
        for(int i = 0; i < n; i++){
            vector<int> t;
            for(int num = 1; num * num <= nums[i]; num++){
                if(nums[i] % num == 0){
                    if(nums[i] / num == num){
                        t.push_back(num);
                    }else{
                        t.push_back(num);
                        t.push_back(nums[i] / num);
                    }
                }
            }
            if(t.size() == 4){
                result += accumulate(t.begin(), t.end(), 0);
            }
        }
        return result;
    }
};
