class Solution {
public:
    string toLower(string& w) {
        string res = "";
        for (int i = 0; i < w.size(); i++) {
            char c = w[i];
            res += tolower(c);
        }
        return res;
    }

    string checkCapitalization(vector<string>& wordlist, string& word) {
        for (auto& w : wordlist) {
            string lower = toLower(w);
            if (lower == word) {
                return w;
            }
        }
        return "";
    }

    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        int n = queries.size();
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<string> ans(n, "");
        unordered_set<string> st(wordlist.begin(), wordlist.end());
        unordered_map<string, string> mp, mp2;
        for (auto& w : wordlist) {
            string lower = toLower(w);
            if(mp.count(lower) == 0)
                mp[lower] = w;            
        }
        for (auto& w : wordlist) {
            string lower = toLower(w);
            string noV = "";
            for(auto& ch : lower){
                if(isVowel(ch)){
                    noV += '*';
                }else{
                    noV += ch;
                }
            }          
            if(mp2.count(noV) == 0){
                mp2[noV] = w;
            }
        }
        for (int i = 0; i < n; i++) { // O(N)
            string word = queries[i];
            // Checking exact match
            if (st.count(word) != 0) { // O(1)
                ans[i] = word;
                continue;
            }
            word = toLower(queries[i]); // O(7)

            // Checking capitalization
            if(mp.count(word) != 0){ // O(1)
                ans[i] = mp[word];
                continue;
            }

            // Checking vowels
            /* for (auto& w : wordlist) { // O(N)
                string lower = toLower(w);
                // cout << lower << " " << w;
                if(lower.size() != word.size()) continue;
                bool flag = true;
                for(int i = 0; i < word.size(); i++){ //O(7)
                    if(word[i] == lower[i] || isVowel(word[i]) && isVowel(lower[i])){
                        continue;
                    }else{
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ans[i] = w;
                    break;
                }
            } */
            string noV = "";
            for(auto& ch : word){
                if(isVowel(ch)){
                    noV += '*';
                }else{
                    noV += ch;
                }
            }
            if(mp2.count(noV) != 0){
                ans[i] = mp2[noV];
            }
        }
        return ans;
    }
};
