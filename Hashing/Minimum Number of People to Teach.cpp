class Solution {
public:

    bool canCommunicate(int u, int v, unordered_map<int, unordered_set<int>>& mp){
        for(auto& l1 : mp[u]){
            if(mp[v].count(l1)) return true;
        }
        return false;
    }

    int findUsers(unordered_map<int, unordered_set<int>>& mp, vector<vector<int>>& frnd, int l, int n){
        int user = 0;
        unordered_set<int> st;
        for(int i = 0; i < frnd.size(); i++){
            int u = frnd[i][0]-1;
            int v = frnd[i][1]-1;
            if(canCommunicate(u, v, mp)) continue;
            if(mp[u].count(l) == 0  && mp[v].count(l) == 0){
                user += 2;
                mp[u].insert(l);
                mp[v].insert(l);
                st.insert(u);
                st.insert(v);
            }else if(mp[u].count(l) == 0){
                user++;
                mp[u].insert(l);
                st.insert(u);
            }else{
                mp[v].insert(l);
                user++;
                st.insert(v);
            }
        }

        for(auto& x : st){
            mp[x].erase(l);
        }

        return user;
    }

    int minimumTeachings(int n, vector<vector<int>>& lang, vector<vector<int>>& frnd) {
        int m = lang.size(), ans = INT_MAX;
        unordered_map<int, unordered_set<int>> mp;
        for(int i = 0; i < m; i++){
            for(auto& x : lang[i]){
                mp[i].insert(x);
            }
        }
        for(int i = 1; i <= n; i++){
            ans = min(ans, findUsers(mp, frnd, i, n));
        }    
        return ans;
    }
};
