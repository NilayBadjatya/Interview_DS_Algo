class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int>  mp;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& ch : s){
            mp[ch]++;
        }
        for(auto& x : mp){
            pq.push(x.second);
        }
        if(mp.size() <= k){
            return 0;
        }
        int toDelete = mp.size() - k, ops = 0;
        while(toDelete--){
            ops += pq.top();
            pq.pop();
        }
        return ops;
    }
};
