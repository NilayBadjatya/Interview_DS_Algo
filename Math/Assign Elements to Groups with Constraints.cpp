class Solution {
public:
    vector<int> assignElements(vector<int>& g, vector<int>& e) {
        unordered_map<int, int> mp;
        for(int i = 0; i < e.size(); i++){
            if(!mp.count(e[i])){
                mp[e[i]] = i;
            }
        }
        vector<int> a(g.size());
        for(int i = 0; i < g.size(); i++){
            int minIdx = INT_MAX;
            for(int j = 1; j*j <= g[i]; j++){
                if(g[i] % j == 0){
                    if(mp.count(j)){
                        minIdx = min(minIdx, mp[j]);
                    }
                    if(mp.count(g[i]/j)){
                        minIdx = min(minIdx, mp[g[i] / j]);
                    }
                }
            }
            a[i] = minIdx == INT_MAX ? -1 : minIdx;
        }
        return a;
    }
};
