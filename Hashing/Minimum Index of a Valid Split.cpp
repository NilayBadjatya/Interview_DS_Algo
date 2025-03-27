class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(auto& x : nums){
            mp[x]++;
        }
        int dominantEle = -1;
        for(auto&x : mp){
            int freq = x.second;
            if(freq > n / 2){
                dominantEle = x.first;
                break;
            }
        }
        int prefixCount = 0, suffixCount = 0;
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = (nums[0] == dominantEle) ? 1  : 0;
        for(int i = 1; i < n; i++){
            if(nums[i] == dominantEle){
                prefix[i] = prefix[i-1] + 1;
            }else{
                prefix[i] = prefix[i-1];
            }
        }
        suffix[n-1] = (nums[n-1] == dominantEle) ? 1  : 0;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] == dominantEle){
                suffix[i] = suffix[i+1] + 1;
            }else{
                suffix[i] = suffix[i+1];
            }
        }
        for(int i = 0; i < n-1; i++){
            int freq1 = prefix[i];
            int freq2 = suffix[i+1];
            if(freq1 > (i+1) / 2 && freq2 > (n - i - 1) / 2){
                return i;
            }
        }
        return -1;
    }
};
