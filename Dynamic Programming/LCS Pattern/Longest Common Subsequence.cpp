class Solution {
public:
    int t[1001][1001];
    int LCS(string& text1, string& text2, int i, int j, int n, int m) {
        if (i == n || j == m) {
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        if (text1[i] == text2[j]) {
            return t[i][j] = 1 + LCS(text1, text2, i + 1, j + 1, n, m);
        }
        return t[i][j] = max(LCS(text1, text2, i, j + 1, n, m),
                   LCS(text1, text2, i + 1, j, n, m));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        memset(t, -1, sizeof(t));
        return LCS(text1, text2, 0, 0, n, m);
    }
};

//Bottom Up Code - 
int LCS(string& s1, string& s2){
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i = 0; i < n+1; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i < m+1; i++){
            dp[0][i] = 0;
        }

        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
