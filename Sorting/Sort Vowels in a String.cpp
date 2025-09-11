class Solution {
public:
    // Capital Letters -> 65 - 90, normal letters -> 97 - 122

    bool isVowel(char a){return a == 'a' || a == 'e' || a == 'i' || a == 'o' ||
                                a == 'u' || a == 'A' || a == 'E' || a == 'I' ||
                                a == 'O' || a == 'U';}

    string sortVowels(string s) {
        int n = s.size();

        vector<char> vowels;
        for (auto& ch : s) {
            if (isVowel(ch))
                vowels.push_back(ch);
        }

        sort(vowels.begin(), vowels.end());

        string t = "";
        int j = 0;
        for(int i = 0; i < n; i++){
            if(isVowel(s[i])){
                t += vowels[j++];
            }else{
                t += s[i];
            }
        }
        return t;
    }
};
