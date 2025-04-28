typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long score = 0, subGk= 0, sum = 0;
        while(j < n){
            sum += nums[j];
            score = (ll)sum * (ll)(j - i + 1);
            while(score >= k){
                subGk += n - j;
                sum -= nums[i];
                i++;
                score = (ll)sum * (ll)(j - i + 1);
            }
            j++;
        }
        long long sub = (ll)n * (ll)(n+1) / 2;
        return sub - subGk;
    }
};
