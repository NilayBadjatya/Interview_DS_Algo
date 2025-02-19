class Solution {
public:

    int nCr(int n, int r){
        int k = r, m = 1;
        while(r--){
            m *= (n--);
        }
        return m / k;
    }

    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), count = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                mp[nums[i] * nums[j]]++;
            }
        }
        for(auto &x : mp){
            count += nCr(x.second, 2) * 8;
        }
        return count;
    }
};
