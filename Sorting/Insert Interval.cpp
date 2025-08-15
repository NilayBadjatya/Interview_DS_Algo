class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector<int> temp = intervals[0];
        vector<vector<int>> merged;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= temp[1]){
                temp[0] = min(temp[0], intervals[i][0]);
                temp[1] = max(temp[1], intervals[i][1]);
            }else{
                merged.push_back(temp);
                temp = intervals[i];
            }
        }
        merged.push_back(temp);
        return merged;
    }
};
