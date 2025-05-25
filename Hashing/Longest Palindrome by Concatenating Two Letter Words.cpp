class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size(), ans = 0;
        unordered_set<string> st(words.begin(), words.end());
        unordered_map<string, int> mp;
        for(auto& s : words){
            mp[s]++;
        }
        bool middle = false;
        for(int i = 0; i < n; i++){
            if(words[i][0] == words[i][1]){
                int f = mp[words[i]];
                if(f % 2 == 0){
                    ans += f * 2;
                }else{
                    if(!middle){
                        ans += 2;
                        middle = true;
                    }
                    ans += (f - 1) * 2;
                }
            }else{
                string t = words[i];
                swap(t[0], t[1]);
                if(st.count(t) != 0){
                    ans += min(mp[words[i]], mp[t]) * 4;
                    mp[t] = 0;
                }
            }
            mp[words[i]] = 0;
        }
        return ans;
    }
};
