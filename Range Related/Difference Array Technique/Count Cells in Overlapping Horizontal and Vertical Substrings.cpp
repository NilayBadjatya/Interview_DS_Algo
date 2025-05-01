class Solution {
public:
    void computeLPS(string& txt, vector<int>& LPS) {
        int n = txt.size();
        LPS[0] = 0;
        int i = 1, len = 0;
        while (i < n) {
            if (txt[i] == txt[len]) {
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

    vector<int> KMP(string& pat, string& txt) {
        int n = txt.size();
        int m = pat.size();
        vector<int> LPS(m, 0);
        computeLPS(pat, LPS);
        int i = 0, j = 0;
        vector<int> result;
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }
            if (j == m) {
                result.push_back(i - j);
                j = LPS[j - 1];
            } else if (pat[j] != txt[i]) {
                if (j != 0) {
                    j = LPS[j - 1];
                } else {
                    i++;
                }
            }
        }
        return result;
    }

    int countCells(vector<vector<char>>& grid, string pattern) {
        int m = grid.size();    // rows
        int n = grid[0].size(); // cols
        int L = pattern.size();
        string h = "", v = "";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                h += grid[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v += grid[j][i];
            }
        }
        vector<int> idxH = KMP(pattern, h);
        vector<int> idxV = KMP(pattern, v);
        int N = m*n;
        vector<int> dh(N+1, 0), dv(N+1, 0);
        for(auto &x : idxH){
            dh[x]++;
            dh[x+L]--;
        }
        for(auto &x : idxV){
            dv[x]++;
            dv[x+L]--;
        }
        vector<int> conH(N, 0), conV(N, 0);
        for(int i = 0, run1 = 0, run2 = 0; i < N; i++){
            run1 += dh[i];
            run2 += dv[i];
            conH[i] = (run1 > 0);
            conV[i] = (run2 > 0);
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int h = i * n + j;
                int v = j * m + i;
                if(conH[h] && conV[v]){
                    ans++;
                }
            }   
        }
        return ans;
    }
};
