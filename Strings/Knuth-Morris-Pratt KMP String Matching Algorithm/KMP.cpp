//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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

    vector<int> search(string& pat, string& txt) {
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
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
