typedef long long ll;
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        vector<int> count(n, 0);
        if(nums[0] % m == k){
            count[0] = 1;
        }
        for(int i = 1; i < n; i++){
            if(nums[i] % m == k){
                count[i] += count[i-1] + 1;
            }else{
                count[i] = count[i-1];
            }
        }
        unordered_map<int, ll> mp;
        ll ans = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++){
            int rem = count[i] % m;
            int toFind = rem - k;
            if(toFind < 0){
                toFind += m;
            }
            if(mp.count(toFind)){
                ans += mp[toFind];
            }
            mp[rem]++;
        }
        return ans;
    }
};
