class Solution {
public:
    string generateTag(string caption) {
        stringstream ss(caption);
        string word;
        string res = "#";

        while(getline(ss, word, ' ')){
            for(int i = 0; i < word.size(); i++){
                word[i] = tolower(word[i]);
            }
            word[0] = toupper(word[0]);
            res += word;
        }

        string final = "";
        for(int i = 0; i < min((int)res.size(), 100); i++){
            if(i > 0 && (res[i] < 0 || res[i] > 127)) continue;
            final += res[i];
        }
        final[1] = tolower(final[1]);
        return final;
    }
};
