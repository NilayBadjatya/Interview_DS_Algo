class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        int n = s.size();
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            mp[s[i] - 'a'] = i;
        }
        
        vector<int> prefix(s.size(), 0);
        prefix[0] = s[0];
        for(int i = 1; i < n; i++){
            prefix[i] = s[i] + prefix[i-1];
        }
        
        vector<int> ans;
        vector<bool> vis(26, false);
        for(int i = 0; i < n; i++){
            int idx = mp[s[i] - 'a'];
            if(idx == i || vis[s[i] - 'a'] || idx == i+1) continue;
            int sum = prefix[idx] - prefix[i] - s[i];
            ans.push_back(sum);
            vis[s[i] - 'a'] = true;
        }
        return ans;
    }
};
