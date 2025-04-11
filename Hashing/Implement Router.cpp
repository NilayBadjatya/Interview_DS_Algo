class Router {
public:
    int n;
    unordered_map<string, int> mp;
    unordered_map<int, deque<int>> destMp;
    deque<vector<int>> q;
    Router(int memoryLimit) { this->n = memoryLimit; }

    bool addPacket(int src, int d, int t) {
        string s = to_string(src) + " " + to_string(d) + " " + to_string(t);
        if (mp.count(s) > 0 && mp[s] > 0) {
            return false;
        }
        if (q.size() == n) {
            string s = to_string(q[0][0]) + " " + to_string(q[0][1]) + " " +
                       to_string(q[0][2]);
            mp[s]--;
            destMp[q[0][1]].pop_front();
            q.pop_front();
        }
        q.push_back({src, d, t});
        mp[s]++;
        destMp[d].push_back(t);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.size() == 0) {
            return {};
        }
        vector<int> t = q.front();
        destMp[t[1]].pop_front();
        string s =
            to_string(t[0]) + " " + to_string(t[1]) + " " + to_string(t[2]);
        mp[s]--;
        q.pop_front();
        return t;
    }

    int getCount(int d, int s, int e) {
        int sidx = -1, eidx = -1;
        if(q.size() == 0) return 0;
        int m = destMp[d].size();
        int l = 0, r = m-1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(destMp[d][mid] >= s){
                sidx = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        l = 0, r = m-1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(destMp[d][mid] <= e){
                eidx = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        if(eidx == -1 || sidx == -1){
            return 0;
        }
        return eidx - sidx + 1;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
