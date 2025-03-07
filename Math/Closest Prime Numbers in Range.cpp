//Time Complexity - O(NloglogN)
class Solution {
public:
    vector<int> SOE(int left, int right){
        vector<bool> primes(right+1, true);
        primes[0] = false;
        primes[1] = false;
        for(int i = 2; i*i <= right; i++){
            if(primes[i]){
                for(int j = i*i; j <= right; j += i){
                    primes[j] = false;   
                }
            }
        }
        vector<int> res;
        for(int i = left; i <= right; i++){
            if(primes[i]){
                res.push_back(i);
            }
        }
        return res;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = SOE(left, right);
        int n = primes.size();
        if(n <= 1){
            return {-1, -1};
        }
        int num1, num2, maxDiff = INT_MAX;
        for(int i = 1; i < n; i++){
            int diff = primes[i] - primes[i-1];
            if(diff < maxDiff){
                maxDiff = diff;
                num1 = primes[i-1];
                num2 = primes[i];
            }
        }
        return {num1, num2};
    }
};
