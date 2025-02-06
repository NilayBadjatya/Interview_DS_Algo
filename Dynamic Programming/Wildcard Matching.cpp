class Solution {
public:
    int dp[2001][2001];
    bool solve(string& s, string& p, int i, int j){
        if(j == p.size() && i == s.size()){
            return true;
        }
        if(i == s.size()){
            for(int i = j; i < p.size(); i++){
                if(p[i] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(p[j] == '*'){
            return dp[i][j] = solve(s,p,i+1,j+1) || solve(s,p,i,j+1) || solve(s,p,i+1,j);
        }else if(p[j] == '?'){
            return dp[i][j] = solve(s,p,i+1,j+1);
        }else if(p[j] == s[i]){
            return dp[i][j] = solve(s,p,i+1,j+1);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        if(s.size() == 0){
            for(auto &ch : p){
                if(ch != '*'){
                    return false;
                }
            }
            return true;
        }
        if(p.size() == 0) return false;
        memset(dp, -1, sizeof(dp));
        return solve(s, p, 0, 0);
    }
};
