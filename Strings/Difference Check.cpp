class Solution {
  public:
  
    int toSecond(string& s){
        int h = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3, 2));
        int se = stoi(s.substr(6, 2));
        return h * 3600 + m * 60 + se;
    }
  
    int findDiff(string& a, string& b){
        int aTime = toSecond(a);
        int bTime = toSecond(b);
        int diff = abs(aTime - bTime);
        diff = min(diff, 86400 - diff);
        return diff;
    }
  
    int minDifference(vector<string> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size(), min_diff = INT_MAX;
        for(int i = 1; i < n; i++){
            int diff = findDiff(arr[i], arr[i-1]);
            min_diff = min(min_diff, diff);
        }
        min_diff = min(min_diff, findDiff(arr[0], arr[n-1]));
        return min_diff;
    }
};
