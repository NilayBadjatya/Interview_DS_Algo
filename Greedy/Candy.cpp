class Solution {
public:
    int candy(vector<int>& r) {
        int n  = r.size();
        vector<int> candies(n, 1);
        for(int i = 1; i < n; i++){
            if(r[i] > r[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }
        for(int i = n-2; i >= 0; i--){
            if(r[i] > r[i+1]){
                if(candies[i] <= candies[i+1]){
                    candies[i] = candies[i+1] + 1;
                }
            }
        }
        int sum = accumulate(candies.begin(), candies.end(), 0);
        return sum;
    }
};
