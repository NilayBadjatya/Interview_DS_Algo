Time Complexity - O(N)
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int miss = 1, n = arr.size();
        // sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            while(arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1]){
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};

Time Complexity - O(NLogN)
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int miss = 1, n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            if(arr[i] <= 0) continue;
            if(arr[i] != miss){
                return miss;
            }
            while(i < n-1 && arr[i+1] == arr[i]){
                i++;
            }
            miss++;
        }
        return miss;
    }
};
