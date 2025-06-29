typedef long long ll;
class Solution {
public:
    int MOD = 1e9 + 7;

    int binaryExpo(ll a, ll b){
        if(b == 0){
            return 1;
        }
        ll half = binaryExpo(a, b/2);
        ll result = (half * half) % MOD;
        if(b % 2 != 0){
            result = (result * a) % MOD;
        }
        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int idx = upper_bound(nums.begin(), nums.end(), target - nums[i]) -
                      nums.begin();
            if(idx <= i) continue;
            idx--;
            cout << idx << " ";
            ans = (ans + binaryExpo(2, idx - i)) % MOD;                    
        }
        return ans;
    }
};
