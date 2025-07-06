class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        int n = a.size();
        vector<int> res;
        priority_queue<vector<int>> pq;
        set<pair<int, int>> st;
        pq.push({a[0]+b[0], 0, 0});
        st.insert({0, 0});
        while(k-- && !pq.empty()){
            int sum = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            res.push_back(sum);
            if(i+1 < n && st.count({i+1, j}) == 0){
                pq.push({a[i+1]+b[j], i+1, j});
                st.insert({i+1, j});
            }
            if(j+1 < n && st.count({i, j+1}) == 0){
                pq.push({a[i]+b[j+1], i, j+1});
                st.insert({i, j+1});
            }
        }
        return res;
    }
};
