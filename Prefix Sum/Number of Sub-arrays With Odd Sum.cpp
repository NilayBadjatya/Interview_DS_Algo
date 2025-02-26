class Solution {
public:
    int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n);
        pref[0] = arr[0];
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] + arr[i];
        }
        int count = 0, even = 0, odd = 0;
        for(int i = 0; i < n; i++){
            if(pref[i] % 2 != 0){
                count = (count + 1 + even) % MOD;
                odd++;
            }else if(pref[i] % 2 == 0){
                count = (count + odd) % MOD;
                even++;
            }
        }
        return count;
    }
};
