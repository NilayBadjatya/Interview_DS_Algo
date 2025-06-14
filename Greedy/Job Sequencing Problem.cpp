class Solution {
  public:
    vector<int> jobSequencing(vector<int> &d, vector<int> &p) {
        // code here
        int n = d.size();
        vector<vector<int>> a;
        int maxDeadline = -1;
        for(int i = 0; i < n; i++){
            a.push_back({d[i], p[i]});
            maxDeadline = max(maxDeadline, d[i]);
        }
        sort(a.begin(), a.end(), [&](vector<int>& x, vector<int>& y){
            if(x[1] == y[1]){
                return x[0] < y[0];
            } 
            return x[1] > y[1];
        });
        
        int profit = 0, jobs = 0;
        vector<int> st(maxDeadline+1, -1);
        for(int i = 0; i < n; i++){
            int slot = a[i][0];
            while(slot > 0 && st[slot] != -1){
                slot--;
            }
            if(slot > 0){
                profit += a[i][1];
                jobs++;
                st[slot] = 1;
            }
        }
        
        return {jobs, profit};
    }
};
