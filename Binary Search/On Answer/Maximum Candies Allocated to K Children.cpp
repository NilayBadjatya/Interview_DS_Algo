class Solution {
public:
    //Time complexity - O(N * LogN)
    bool isValid(vector<int>& candies, int mid, long long k){
        long long c = 0;
        for(int i = 0; i < candies.size(); i++){
            c += (candies[i] / mid);
        }
        return c >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if(sum < k){
            return 0;
        }
        int maxi = *max_element(candies.begin(), candies.end());
        int l = 1, r = maxi, ans = -1;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if(isValid(candies, mid, k)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};
