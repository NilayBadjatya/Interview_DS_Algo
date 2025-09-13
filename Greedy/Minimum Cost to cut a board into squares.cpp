class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());
        int xs = x.size();
        int ys = y.size();
        int i = 0, j = 0, v = 1, h = 1, cost = 0;
        while(i < xs && j < ys){
            if(x[i] > y[j]){
                cost += (x[i++] * h);
                v++;
            }else{
                cost += (y[j++] * v);
                h++;
            }
        }
        
        while(i < xs){
            cost += (x[i++] * h);
            v++;
        }
        
        while(j < ys){
            cost += (y[j++] * v);
            h++;
        }
        
        return cost;
    }
};
