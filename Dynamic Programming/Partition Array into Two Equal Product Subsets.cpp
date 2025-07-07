class Solution {
public:

    bool solve(vector<int>& nums, int i, long long prd, long long target, unordered_set<int>& idx){
        if(prd == target){
            long long temp = 1;
            for(int i = 0 ; i < nums.size(); i++){
                if(idx.count(i) != 0) continue;
                temp *= nums[i];
                if(temp > prd) return false;
            }
            if(temp == prd) return true;
            return false;
        }
        if(prd > target){
            return false;
        }
        if(i == nums.size()){
            return false;
        }
        unordered_set<int> idx2 = idx;
        idx2.insert(i);
        return solve(nums, i+1, prd*nums[i], target, idx2) || solve(nums, i+1, prd, target, idx);
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        unordered_set<int> idx;
        return solve(nums, 0, 1, target, idx);
    }
};
