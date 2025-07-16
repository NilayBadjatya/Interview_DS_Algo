class Solution {
  public:
  
    vector<bool> sieve(int n){
        vector<bool> primes(n, true);
        primes[0] = primes[1] = false;
        for(int i = 2; i * i <= n; i++){
            if(primes[i]){
                for(int j = i*i; j < n; j += i){
                    primes[j] = false;
                }
            }
        }
        return primes;
    }
    
    bool power(int x, int n){
        long long val = 1;
        for(int i = 0; i < 8; i++){
            val *= x;
            if(val > n){
                return false;
            }
        }
        return true;
    }
  
    int countNumbers(int n) {
        // Code Here
        vector<bool> primes = sieve(sqrt(n) + 1);
        vector<int> square;
        int count = 0;
        for(int i = 0; i < primes.size(); i++){
            if(primes[i]){
                if(power(i, n)){
                    count++;
                }
                square.push_back(i);
            }
        }
        
        int sz = square.size();
        for(int i = 0; i < sz; i++){
            for(int j = i+1; j < sz; j++){
                int x = square[i];
                int y = square[j];
                long long val = 1LL * x * x * y * y;
                if(val <= n){
                    count++;
                }else{
                    break;
                }
            }
        }
        return count;
    }
};
