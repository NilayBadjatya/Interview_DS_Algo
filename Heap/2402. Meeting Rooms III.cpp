typedef long long ll;
typedef pair<ll, ll> P;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<P, vector<P>, greater<P>> isUsed;
        priority_queue<ll, vector<ll>, greater<ll>> available;
        vector<ll> rooms(n, 0);
        for(ll i = 0; i < n; i++){
            available.push(i);
        }
        sort(meetings.begin(), meetings.end());
        for(auto& x : meetings){
            ll start = x[0];
            ll end = x[1];
            while(!isUsed.empty() && start >= isUsed.top().first){
                available.push(isUsed.top().second);
                isUsed.pop();
            }
            if(!available.empty()){
                ll room = available.top();
                available.pop();
                isUsed.push({end, room});
                rooms[room]++;
            }else if(!isUsed.empty()){
                ll t = isUsed.top().first;
                ll room = isUsed.top().second;
                isUsed.pop();
                isUsed.push({t + (end - start), room});
                rooms[room]++;
            }
        }
        ll maxi = *max_element(rooms.begin(), rooms.end());
        for(ll i = 0; i < n; i++){
            if(rooms[i] == maxi) return i;
        }
        return -1;
    }
};
