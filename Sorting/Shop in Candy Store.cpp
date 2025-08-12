class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n = prices.size();
        sort(prices.begin(), prices.end());
        int i = 0, j = n-1;
        int miniCost = 0, maxiCost = 0;
        while(i <= j){
            miniCost += prices[i];
            i++;
            j -= k;
        }
        
        i = 0, j = n-1;
        // int miniCost = 0, maxiCost = 0;
        while(i <= j){
            maxiCost += prices[j];
            j--;
            i += k;
        }
        return {miniCost, maxiCost};
    }
};
