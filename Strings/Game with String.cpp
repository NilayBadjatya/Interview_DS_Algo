class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        vector<int> freq(26, 0);
        for(auto& ch : s){
            freq[ch - 'a']++;
        }
        priority_queue<int> pq;
        for(auto& x : freq){
            if(x == 0) continue;
            pq.push(x);
        }
        while(k--){
            int x = pq.top();
            pq.pop();
            x--;
            pq.push(x);
        }
        int score = 0;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            score += (x * x);
        }
        return score;
    }
};
