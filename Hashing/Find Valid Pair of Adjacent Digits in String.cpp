class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> mp;
        for(auto &ch : s){
            mp[ch]++;
        }
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i-1]){
                if(mp[s[i]] == s[i] - '0' && mp[s[i-1]] == s[i-1] - '0'){
                    string t = "" ;
                    t += s[i-1];
                    t += s[i];
                    return t;
                }
            }
        }
        return "";
    }
};
