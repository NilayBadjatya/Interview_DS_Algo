class Solution {
public:

    void solve(string& tiles, unordered_set<string>& st, string t, unordered_map<char, int>& mp){
        if(t.size() > 0){
            st.insert(t);
        }
        if(t.size() == tiles.size()){
            return;
        }
        for(int j = 0; j < tiles.size(); j++){
            if(mp[tiles[j]] > 0){
                t += tiles[j];
                mp[tiles[j]]--;
                solve(tiles, st, t, mp);
                t.pop_back();
                mp[tiles[j]]++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        unordered_map<char, int> mp;
        for(auto& ch: tiles){
            mp[ch]++;
        }
        if(n == 1){
            return 1;
        }
        unordered_set<string> st;
        solve(tiles, st, "", mp);
        for(auto &s : st){
            cout << s << " ";
        }
        return st.size();
    }
};
