class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int i = 0, ans = 0;
        int n = s.size();
        while(i < n){
            if(i < n-1 && mp[s[i]] < mp[s[i+1]]){
                ans += (mp[s[i+1]] - mp[s[i]]);
                i++;
            }else{
                ans += mp[s[i]];
            }
            i++;
        }
        return ans;
    }
};
