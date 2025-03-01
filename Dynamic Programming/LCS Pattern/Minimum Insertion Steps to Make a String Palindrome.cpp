class Solution {
public:

    string LCS(string& s1, string& s2){
        int n = s1.size();
        vector<vector<int>> t(n+1, vector<int> (n+1));
        for(int i = 0; i < n+1; i++){
            t[i][0] = 0;
            t[0][i] = 0;
        }
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < n+1; j++){
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = t[i-1][j-1] + 1;
                }else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        string lcs = "";
        int i = n, j = n;
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                lcs.push_back(s1[i-1]);
                i--;
                j--;
            }else if(t[i-1][j] > t[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }

    int minInsertions(string s1) {
        int n = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        string lcs = LCS(s1, s2);
        return n - lcs.size();
    }
};
