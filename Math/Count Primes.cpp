class Solution {
public:

    int sieve(int n){
        vector<int> isPrime(n+1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i * i <= n; i++){
            if(isPrime[i]){
                for(int j = i*i; j <= n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(isPrime[i]) count++;
        }
        return count;
    }

    int countPrimes(int n) {
        if(n == 0){
            return 0;
        }
        return sieve(n);
    }
};
