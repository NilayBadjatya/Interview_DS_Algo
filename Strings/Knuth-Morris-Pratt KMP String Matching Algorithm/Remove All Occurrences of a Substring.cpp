//Time Complexity - O(N + M) 
class Solution {
public:
    void computeLPS(string& pat, vector<int>& LPS) {
        int m = pat.size();
        int i = 1, len = 0;
        LPS[0] = 0;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }

    int firstOccurence(string& txt, string& pat, vector<int>& LPS) {
        int n = txt.size();
        int m = pat.size();
        int i = 0, j = 0;
        while (i < txt.size()) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return i-m;
                j = LPS[j - 1];
            } else if (pat[j] != txt[i]) {
                if (j != 0) {
                    j = LPS[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }

    string removeOccurrences(string txt, string pat) {
        int n = txt.size();
        int m = pat.size();
        vector<int> LPS(m, 0);
        computeLPS(pat, LPS);
        while(true){
            int first = firstOccurence(txt, pat, LPS);
            if(first == -1){
                break;
            }
            txt = txt.substr(0, first) + txt.substr(first + m);
        }
        return txt;
    }
};
