class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(arr[0] == 0) return -1;
        int jumps = 0, maxReach = 0, currentEnd = 0;
        for(int i = 0; i < n; i++){
            maxReach = max(maxReach, i + arr[i]);
            if(maxReach >= n-1) return jumps+1;
            if(i == currentEnd && maxReach == i) return -1;
            if(i == currentEnd){
                jumps++;
                currentEnd = maxReach;
            }
        }
        return jumps;
    }
};
