typedef long long ll;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq(nums.begin(), nums.end());
        ll ops = 0;
        while(pq.top() < k && pq.size() >= 2){
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            ll newEle = min(x, y) * 2 + max(x, y);
            pq.push(newEle);
            ops++;
        }
        return ops;
    }
};
