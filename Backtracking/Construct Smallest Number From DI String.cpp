class Solution {
public:
    bool isValid(string& pat, string& t) {
        int n = pat.size();
        for (int i = 0; i < n; i++) {
            if (pat[i] == 'I') {
                if (t[i] >= t[i + 1]) {
                    return false;
                }
            } else if (pat[i] == 'D') {
                if (t[i] <= t[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }

    void solve(string& pat, int i, string t, vector<string>& a, vector<bool>& isUsed) {
        if (t.size() == pat.size() + 1) {
            if (isValid(pat, t))
                a.push_back(t);
            return;
        }
        for (int num = 1; num <= 9; num++) {
            if(isUsed[num]) continue;
            if(pat[i] == 'I')
            t += (num + '0');
            isUsed[num] = true;
            solve(pat, t, a, isUsed);
            t.pop_back();
            isUsed[num] = false;
        }
    }

    string smallestNumber(string pat) {
        vector<string> a;
        vector<bool> isUsed(10, false);
        solve(pat, 0, "", a, isUsed);
        sort(a.begin(), a.end());
        return a[0];
    }
};
