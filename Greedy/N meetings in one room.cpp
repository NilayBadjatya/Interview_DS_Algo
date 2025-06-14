class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<vector<int>> a;
        for(int i = 0; i < n; i++){
            a.push_back({end[i], start[i]});
        }
        sort(a.begin(), a.end());
        
        int meet = 1, prev = a[0][0];
        for(int i = 1; i < n; i++){
            if(a[i][1] > prev){
                meet++;
                prev = a[i][0];
            }
        }
        
        return meet;
    }
};
