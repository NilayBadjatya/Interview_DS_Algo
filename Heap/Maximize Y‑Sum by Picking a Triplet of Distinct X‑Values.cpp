typedef pair<int, int> P;
class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = y.size();
        priority_queue<P> pq;
        for(int i = 0; i < n; i++){
            pq.push({y[i], i});
        }
        int sum = 0, count = 0;
        unordered_set<int> st;
        while(!pq.empty() && count < 3){
            int val = pq.top().first;
            int idx = pq.top().second;
            if(st.count(x[idx]) == 0){
                sum += val;
                count++;
                st.insert(x[idx]);
            }
            pq.pop();
        }
        if(count != 3) return -1;
        return sum;
    }
};
