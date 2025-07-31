class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> curr, prev, result;

        for(int i = 0; i < n; i++){
            for(auto& x : prev){
                curr.insert(x | nums[i]);
                result.insert(x | nums[i]);
            }
            curr.insert(nums[i]);
            result.insert(nums[i]);
            prev = curr;
            curr.clear();
        }

        return (int) result.size();
    }
};
