class Solution {
public:

    int maxDiff(int num) {
        string s = to_string(num);
        string s2 = s;
        string s22 = s;
        int i = 0;
        while (i < s.size() && s[i] == '9') {
            i++;
        }
        if (i < s.size()) {
            char c = s[i];
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == c) {
                    s[j] = '9';
                }
            }
        }

        i = 1;
        while (i < s2.size() && (s2[i] == '0' || s2[i] == s2[0])) {
            i++;
        }
        if (i < s2.size()) {
            char first = s2[0];
            char c = s2[i];
            for (int j = 0; j < s2.size(); j++) {
                if (s2[j] == c) {
                    s2[j] = '0';
                }
            }
        }
        
        i = 0;
        while (i < s22.size() && s22[i] == '1') {
            i++;
        }
        if (i < s22.size()) {
            char c = s22[i];
            for (int j = 0; j < s22.size(); j++) {
                if (s22[j] == c) {
                    s22[j] = '1';
                }
            }
        }
        s2 = min(s2, s22);
        return stoi(s) - stoi(s2);
    }
};
