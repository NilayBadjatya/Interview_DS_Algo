// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> a;
        
        for(int i = 0; i < n; i++){
            a.push_back({val[i], wt[i]});
        }
        sort(a.begin(), a.end(), [&](vector<int>& p, vector<int>& q){
            double x = (p[0] * 1.0) / p[1]; 
            double y = (q[0] * 1.0) / q[1];
            return x > y;
        });
        
        double profit = 0;
        for(int i = 0; i < n; i++){
            if(a[i][1] <= capacity){
                capacity -= a[i][1];
                profit += a[i][0];
            }else{
                profit += ((capacity * 1.0 / a[i][1]) * a[i][0]);
                capacity = 0;
            }
        }
        
        return profit;
    }
};
