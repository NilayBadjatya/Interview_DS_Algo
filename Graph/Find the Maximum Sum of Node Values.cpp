class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> delta(n);
        for(int i = 0; i < n; i++){
            delta[i] = (nums[i] ^ k) - nums[i]; // storing the differences in the value of each node after performing XOR operation
        }
        sort(delta.begin(), delta.end(), greater<int>()); //Sorting it in descending order so that we should take only those nodes which will give us maximum value after XOR operation
        long long res = 0;
        for(auto& x : nums){
            res += x;
        }
        for(int i = 0; i < n-1; i += 2){
            long long change = delta[i] + delta[i+1];
            if(change > 0){
                res += change;
            }
        }
        return res;
    }
};
