class Solution {
public:
    int MOD = 1e9+7;
    long long fact(long long n){
        if(n == 0){
            return 1;
        }
        return (n * fact(n-1)) % MOD;
    }

    int countPermutations(vector<int>& c) {
        int n = c.size();
        int mini = INT_MAX;
        for(int i = 1; i < n; i++){
            mini = min(mini, c[i]);
        }

        if(mini <= c[0]){
            return 0;
        }
        return fact(n-1) % MOD;
    }
};
