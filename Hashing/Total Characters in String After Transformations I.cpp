class Solution {
public:
    int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> a(26, 0);
        int n = s.size();
        for(int i = 0; i < n; i++){
            a[s[i] - 'a']++;
        }
        while(t--){
            int z = a[25];
            for(int i = 25; i > 0; i--){
                a[i] = a[i-1];
            }
            a[0] = z % MOD;
            a[1] = (a[1] + z) % MOD;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans = (ans + a[i]) % MOD; 
        }
        return ans;
    }
};
