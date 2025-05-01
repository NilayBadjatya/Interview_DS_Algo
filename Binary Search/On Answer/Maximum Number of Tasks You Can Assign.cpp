class Solution {
public:

    bool isValid(vector<int>& tasks, vector<int>& workers, int mid, int pills, int strength){
        int pillsUsed = 0;
        multiset<int> st(workers.begin(), workers.begin() + mid);
        for(int i = mid - 1; i >= 0; i--){
            int req = tasks[i];
            auto it = prev(st.end());
            if(*it >= req){
                st.erase(it);
            }else if(pillsUsed >= pills){
                return false;
            }else{
                auto weakestWorker = st.lower_bound(req - strength);
                if(weakestWorker == st.end()){
                    return false;
                }
                st.erase(weakestWorker);
                pillsUsed++;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());
        int l = 0, r = min(m, n), ans = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(isValid(tasks, workers, mid, pills, strength)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};
