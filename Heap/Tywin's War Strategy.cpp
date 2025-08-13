class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int picks = ceil(n * 1.0 / 2);
        priority_queue<int> pq;
        for(int i = 0; i < n; i++){ // O(NLogN)
            int x = ceil(arr[i] * 1.0 / k);
            int to = x * k;
            int diff = to - arr[i];
            // cout << diff << " ";
            pq.push(diff);
            if(pq.size() > picks){
                pq.pop();
            }
        }
        
        int sum = 0;
        while(!pq.empty()){ //O(n/2Log(n/2))
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
