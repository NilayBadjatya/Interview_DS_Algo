class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        unordered_map<int, int> mp;
        int n = s.size();
        int i = 0, j = 0, ans = 0;
        while(j < n){
            mp[s[j]]++;
            if(j - i + 1 < k){
                j++;
            }else if(j - i + 1 == k){
                if(mp.size() == (k-1)){
                    ans++;
                }
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
