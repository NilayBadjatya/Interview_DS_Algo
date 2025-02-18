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

    int KMP(string& txt, string& pat){
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
                return 1;
            }else if(i < n && pat[j] != txt[i]){
                if(j != 0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return -1;
    }

    int repeatedStringMatch(string a, string b) {
        string t = "";
        int occ = ceil((b.size() * 1.0) / a.size());
        int w = occ;
        while(occ--){
            t += a;
        }
        int cnt = 0;
        while(true){
            int x = KMP(t, b);
            if(x != -1){
                return cnt + w;
            }
            t += a;
            cnt++;
            if(cnt > 3){
                return -1;
            }
        }
        return -1;
    }
};
