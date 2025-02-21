class Solution {
public:
    int MOD = 1e9+7;
    int findReverse(int x){
        string s = to_string(x);
        reverse(s.begin(), s.end());
        return stoi(s);
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> reversed(n);
        for(int i = 0; i < n; i++){
            reversed[i] = findReverse(nums[i]);
        }
        int pairs = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int x = nums[i] - reversed[i];
            if(mp.count(x) != 0){
                pairs = (pairs + mp[x]) % MOD;
            }
            mp[x]++;
        }
        return pairs % MOD;
    }
};
