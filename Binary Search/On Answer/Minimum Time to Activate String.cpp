typedef long long ll;
class Solution {
public:

    bool isValid(string s, vector<int>& order, int mid, int k){
        int n = s.size();
        for(int i = 0; i <= mid; i++){
            s[order[i]] = '*';
        }

        ll subs = 0, prev = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                subs += 1LL * (i - prev) * (n-i);
                prev = i;
            }
        }
        return subs >= k;
    }

    int minTime(string s, vector<int>& order, int k) {
        int n = order.size();
        int l = 0, r = n-1, ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(isValid(s, order, mid, k)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
