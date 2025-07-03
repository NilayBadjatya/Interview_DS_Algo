class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int i = 0, j = 0, ans = -1;
        unordered_map<char, int> mp;
        while(j < n){
            mp[s[j]]++;
            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            if(mp.size() == k){
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        return ans;
    }
};
