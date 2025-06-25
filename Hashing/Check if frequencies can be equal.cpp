class Solution {
  public:
  
    bool check(unordered_map<char, int>& mp){
        int prev = -1;
        for(auto& x : mp){
            if(x.second == 0) continue;
            if(prev == -1){
                prev = x.second;
            }else if(x.second != prev){
                return false;
            }
            prev = x.second;
        }
        return true;
    }
  
    bool sameFreq(string& s) {
        // code here
        int n = s.size();
        unordered_map<char, int> mp;
        for(auto& ch : s){
            mp[ch]++;
        }
        
        unordered_set<char>st;
        if(check(mp)){
            return true;
        }
        for(int i = 0; i < n; i++){
            if(st.count(s[i]) != 0) continue;
            mp[s[i]]--;
            if(check(mp)){
                return true;
            }
            mp[s[i]]++;
            st.insert(s[i]);
        }
        return false;
    }
};
