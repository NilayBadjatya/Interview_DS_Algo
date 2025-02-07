class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> col;
        unordered_map<int, int> btoc;
        unordered_set<int> ispresent;
        vector<int> res;
        int c = 0 ;
        for(auto &q : queries){
            int ball = q[0];
            int color = q[1];
            if(ispresent.count(ball) == 0){
                if(col[color] == 0){
                    c++;
                }
                col[color]++;
            }else{
                col[btoc[ball]]--;
                if(col[btoc[ball]] == 0){
                    c--;
                }
                if(col[color] == 0){
                    c++;
                }
                col[color]++;
            }
            ispresent.insert(ball);
            btoc[ball] = color;
            res.push_back(c);
        }
        return res;
    }
};
