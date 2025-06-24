class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> idx;
        int r = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] == key){
                int l = max(r, j - k);
                r = min(n-1, j + k) + 1;
                for(int i = l; i < r; i++){
                    idx.push_back(i);
                }
            }
        }
        return idx;
    }
};
