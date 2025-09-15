class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> freq(26, 0);
        for(auto& ch : brokenLetters){
            freq[ch - 'a']++;
        }

        stringstream ss(text);
        string word;
        int count = 0;
        while(getline(ss, word, ' ')){
            bool flag = true;
            for(auto& ch : word){
                if(freq[ch - 'a'] > 0){
                    // cout << ch << " ";
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};
