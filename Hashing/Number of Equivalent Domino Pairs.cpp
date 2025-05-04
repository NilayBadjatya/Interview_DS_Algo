class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        int n = d.size(), pairs = 0;
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++){
            string s = "", rev = ""; 
            s = to_string(d[i][0]) + ' ' + to_string(d[i][1]);
            rev = s;
            swap(rev[0], rev[2]);
            if(mp[s] > 0){
                pairs += mp[s];
            }
            if(s != rev && mp[rev] > 0){
                pairs += mp[rev];
            }
            mp[s]++;
        }
        return pairs;
    }
};
