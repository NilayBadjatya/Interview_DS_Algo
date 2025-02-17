class Solution {
public:

    void computeLPS(string& pat, vector<int>& lps){
        int m = pat.size();
        lps[0] = 0;
        int i = 1, len = 0;
        while(i < m){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int strStr(string txt, string pat) {
        int n = txt.size();
        int m = pat.size();
        vector<int> lps(m, 0);
        computeLPS(pat, lps);
        int i = 0, j = 0;
        while(i < n){
            if(pat[j] == txt[i]){
                i++;
                j++;
            }
            if(j == m){
                return i-m;
            }else if(pat[j] != txt[i]){
                if(j != 0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return -1;
    }
};
