class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        vector<vector<int>> a;
        for(int i = 0; i < n; i++){
            a.push_back({arr[i], dep[i]});
        }
        sort(a.begin(), a.end());
        
        pq.push(a[0][1]);
        int platforms = 1;
        for(int i = 1; i < n; i++){
            if(a[i][0] > pq.top()){
                pq.pop();
                pq.push(a[i][1]);
            }else{
                platforms++;
                pq.push(a[i][1]);
            }
        }
        
        return platforms;
    }
};
