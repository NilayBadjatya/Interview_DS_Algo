//Approach 1: Top Down DP
//Here the main key to solve this question is to only take those same characters that are at different indexes.
class Solution {
  public:
    int t[1001][1001];
    int LCS(string& s1, string& s2, int i, int j){
        if(i == s1.size() || j == s2.size()){
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(s1[i] == s2[j] && i != j){
            return t[i][j] = 1 + LCS(s1, s2, i+1, j+1);
        }
        return t[i][j] = max(LCS(s1, s2, i+1, j), LCS(s1, s2, i, j+1));
    }
  
    int LongestRepeatingSubsequence(string &s) {
        memset(t, -1, sizeof(t));
        return LCS(s, s, 0, 0);
    }
};

//Approach 2: Bottom Up DP
class Solution {
  public:
    int LongestRepeatingSubsequence(string &s) {
        int n = s.size();
        vector<vector<int>> t(n+1, vector<int> (n+1));
        for(int i = 0; i < n+1; i++){
            t[i][0] = 0;
            t[0][i] = 0;
        }
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < n+1; j++){
                if(s[i-1] == s[j-1] && i != j){
                    t[i][j] = 1 + t[i-1][j-1];
                }else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[n][n];
    }
};
