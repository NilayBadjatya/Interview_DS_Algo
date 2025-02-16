typedef long long ll;
class Solution {
public:
    long long maxWeight(vector<int>& p) {
        int n = p.size();
        priority_queue<int> pq(p.begin(), p.end());
        int c = n / 4, even = c / 2, odd = c - even;
        ll sum = 0;
        while(odd--){
            sum += pq.top();
            pq.pop();
        }
        while(even--){
            pq.pop();
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
