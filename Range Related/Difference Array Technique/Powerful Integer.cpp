class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        // sort(intervals.begin(), intervals.end());
        
        int n = intervals.size(), maxi = INT_MIN;
        map<int, int> diff;
        for(int i = 0; i < n; i++){
            diff[intervals[i][0]]++;
            diff[intervals[i][1]+1]--;
        }
        
        int sum = 0, last = diff.begin()->first;
        for(auto& x : diff){
            int curr = x.first;
            if(sum >= k){
                maxi = curr-1;
            }
            sum += x.second;
        }
        
        return maxi == INT_MIN ? -1 : maxi;
    }
};
