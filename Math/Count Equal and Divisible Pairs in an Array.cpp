class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> indices;
        for(int i = 0; i < n; i++){
            indices[nums[i]].push_back(i);
        }
        unordered_set<int> div;
        for(int i = 1; i * i <= k; i++){
            if(k % i == 0){
                div.insert(i);
                div.insert(k / i);
            }
        }
        int result = 0;
        for(auto& [_, arr] : indices){
            unordered_map<int, int> mp;
            for(auto& x : arr){
                int gcd = __gcd(k, x);
                int j = k / gcd;
                result += mp[j];
                for(auto& x1 : div){
                    if(x % x1 == 0){
                        mp[x1]++;
                    }
                }
            }
        }
        return result;
    }
};
