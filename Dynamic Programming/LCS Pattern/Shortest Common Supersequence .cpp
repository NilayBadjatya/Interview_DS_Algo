class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> t(n+1, vector<int>(m+1));
        for(int i = 0; i < n; i++){
            t[i][0] = 0;
        }
        for(int i = 0; i < m; i++){
            t[0][i] = 0;
        }
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = t[i-1][j-1] + 1;
                }else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        string lcs = "";
        int i = n, j = m;
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                lcs.push_back(s1[i-1]);
                i--;
                j--;
            }else if(t[i-1][j] > t[i][j-1]){
                lcs.push_back(s1[i-1]);
                i--;
            }else{
                lcs.push_back(s2[j-1]);
                j--;
            }
        }
        while(i > 0){
            lcs.push_back(s1[i-1]);
            i--;
        }
        while(j > 0){
            lcs.push_back(s2[j-1]);
            j--;
        }
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};
