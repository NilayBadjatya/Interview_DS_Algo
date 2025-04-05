//Java Code :-
class Solution {
    public int arrayPairSum(int[] nums) {
        int n = nums.length, sum = 0;
        Arrays.sort(nums);
        for(int i = n-2; i >= 0; i -= 2){
            sum += Math.min(nums[i], nums[i+1]);
        }
        return sum;
    }
}

//C++ Code:-
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = n-2; i >= 0; i -= 2){
            sum += min(nums[i], nums[i+1]);
        }
        return sum;
    }
};
