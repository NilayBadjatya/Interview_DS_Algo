class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    bool isValid(string s) {
        int n = s.size(), count = 0, vowel = 0, consonents = 0;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                count++;
                continue;
            }
            if (s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122) {
                count++;
                if (isVowel(s[i])) {
                    vowel++;
                } else {
                    consonents++;
                }
                continue;
            }
            return false;
        }
        return count >= 3 && vowel > 0 && consonents > 0;
    }
};
