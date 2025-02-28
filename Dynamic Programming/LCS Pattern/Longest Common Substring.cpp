//Approach 1 : Recursion + Memoisation (TLE / MLE)
class Solution {
  public:
    int t[1001][1001][1001];
    int LCSubstring(string& s1, string& s2, int i, int j, int n, int m, int len){
        if(i == n || j == m){
            return len;
        }
        if(t[i][j][len] != -1){
            return t[i][j][len];
        }
        int currLen = 0;
        if(s1[i] == s2[j]){
            currLen = LCSubstring(s1, s2, i+1, j+1, n, m, len+1);
        }
        int l1 = LCSubstring(s1, s2, i, j+1, n, m, 0);
        int l2 = LCSubstring(s1, s2, i+1, j, n, m, 0);
        return t[i][j][len] = max({currLen, l1, l2});
    }
  
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        return LCSubstring(s1, s2, 0, 0, n, m, 0);
    }
};

//Approach 2: Bottom Up DP
//Time Complexity - O(N*M)
class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        int res = 0;
        vector<vector<int>> t(n+1, vector<int>(m+1));
        for(int i = 1;i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = t[i-1][j-1] + 1;
                    res = max(res, t[i][j]);
                }else{
                    t[i][j] = 0;
                }
            }
        }
        return res;
    }
};
