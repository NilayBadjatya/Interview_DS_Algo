class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {\
        int n = nums.size();
        vector<int> powers(n, 0);

        for(int i = 0; i < n; i++){
            int temp = nums[i];
            while(temp % 2 == 0){
                temp /= 2;
                powers[i]++;
            }
        }

        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long gcd = nums[i], mini = powers[i];
            ans = max(ans, nums[i] * 2LL);
            vector<int> freq(32, 0);
            for(int j = i; j < n; j++){
                mini = min(mini, 1LL * powers[j]); 
                freq[powers[j]]++;
                gcd = __gcd(gcd, 1LL * nums[j]);
                if(freq[mini] <= k){
                    ans = max(ans, gcd * 2LL * (j- i + 1));
                }else{
                    ans = max(ans, 1LL * gcd * (j - i + 1));
                }
            }
        }

        return ans;
    }
};
