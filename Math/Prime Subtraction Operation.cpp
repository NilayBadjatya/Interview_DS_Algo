class Solution {
public:
    vector<int> sieve(int n){
        vector<int> primes(n+1, true);
        primes[0] = false;
        primes[1] = false;
        for(int i = 2; i*i <= n; i++){
            if(primes[i]){
                for(int j = i*i; j <= n; j += i){
                    primes[j] = false;
                }
            }
        }
        return primes;
    }
    bool isStrictlyIncreasing(vector<int>& nums){
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                return false;
            }
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> primes = sieve(maxi);
        for(int i = nums[0]-1; i >= 0; i--){
            if(primes[i]){
                nums[0] -= i;
                break;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = nums[i]-1; j >= 0; j--){
                if(primes[j]){
                    if(nums[i] - j > nums[i-1]){
                        nums[i] -= j;
                        break;
                    }
                }
            }
        }
        return isStrictlyIncreasing(nums);
    }
};
