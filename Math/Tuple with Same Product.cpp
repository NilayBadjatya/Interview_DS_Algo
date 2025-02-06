class Solution {
public:

    int nCr(int n, int r){
        int sum = 1, k = r;
        while(r--){
            sum *= n;
            n--;
        }
        return sum / k;
    }

    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int x = nums[i] * nums[j];
                mp[x]++;
            }
        }
        int count = 0;
        for(auto &x : mp){
            int pairs = nCr(x.second, 2);
            count += (pairs * 8);
        }
        return count;
    }
};
