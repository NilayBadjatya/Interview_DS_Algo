class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        int n = mices.size();
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        int time = 0;
        for(int i = 0; i < n; i++){
            time = max(time, abs(mices[i] - holes[i]));
        }
        return time;
    }
};
