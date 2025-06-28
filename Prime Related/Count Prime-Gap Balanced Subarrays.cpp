class Solution {
public:
    
    vector<bool> sieve(int n){
        vector<bool> primes(n+1, true);
        primes[0] = primes[1] = false;
        for(int i = 2; i * i <= n; i++){
            if(primes[i]){
                for(int j = i * i; j <= n; j += i){
                    primes[j] = false;
                }
            }
        }
        return primes;
    }

    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> primes = sieve(5 * 1e4);
        multiset<int> st;
        int i = 0, j = 0, prev = -1, curr = -1, countPrimes = 0, ans = 0;
        while(j < n){
            if(primes[nums[j]]){
                countPrimes++;
                prev = curr;
                curr = j;
                st.insert(nums[j]);
            }
            while(st.size() > 0 && (*st.rbegin() - *st.begin()) > k){
                if(primes[nums[i]]){
                    st.erase(st.find(nums[i]));
                    countPrimes--;
                }
                i++;
            }
            if(countPrimes >= 2 && (*st.rbegin() - *st.begin()) <= k){
                ans += prev - i + 1;
            }
            j++;
        }
        return ans;
    }
};
