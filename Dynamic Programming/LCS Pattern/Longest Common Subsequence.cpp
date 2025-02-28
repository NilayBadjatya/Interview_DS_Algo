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
