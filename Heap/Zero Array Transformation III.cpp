class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        int Q = q.size();
        int queryUsed = 0; // for storing the number of queries used
        sort(q.begin(), q.end());
        priority_queue<int> pq; // for storing end point query index
        priority_queue<int, vector<int>, greater<int>> past; // for storing past end point query index
        int j = 0; // pointer for queries
        for(int i = 0; i < n; i++){
            while(j < Q && q[j][0] <= i && q[j][1] >= i){
                pq.push(q[j][1]);
                j++;
            }
            nums[i] -= past.size();
            while(nums[i] > 0 && !pq.empty() && pq.top() >= i){
                int idx = pq.top();
                pq.pop();
                queryUsed++;
                nums[i]--;
                past.push(idx);
            }
            if(nums[i] > 0){
                return -1;
            }
            while(!past.empty() && past.top() <= i){
                past.pop();
            }
        }
        return Q - queryUsed;
    }
};
