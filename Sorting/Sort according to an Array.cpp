class Solution {
  public:
    void relativeSort(vector<int>& a1, vector<int>& a2) {
        // code here
        unordered_map<int, int> mp;
        for(int i = 0; i < a2.size(); i++){
            if(mp.count(a2[i]) == 0){
                mp[a2[i]] = i;
            }
        }
        
        sort(a1.begin(), a1.end(), [&](int x, int y){
            if(mp.count(x) && mp.count(y)){
                int idX = mp[x];
                int idY = mp[y];
                return idX < idY;
            }
            if(mp.count(x)) return true;
            if(mp.count(y)) return false;
            return x < y;
        });
    }
};
