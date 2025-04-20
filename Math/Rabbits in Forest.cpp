class Solution {
public:
    int numRabbits(vector<int>& a) {
        unordered_map<int, int> mp;
        int n = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != 0 && mp.count(a[i]) > 0 && mp[a[i]] > 0){
                mp[a[i]]--;
                continue;
            }
            n += a[i];
            n++;
            mp[a[i]] = a[i];
        } 
        return n;
    }
};
