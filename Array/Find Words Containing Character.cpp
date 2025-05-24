// Approach 1:

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> indices;
        for(int i = 0; i < n; i++){
            for(auto& ch : words[i]){
                if(ch == x){
                    indices.push_back(i);
                    break;
                }
            }
        }
        return indices;
    }
};

// Approach 2:

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> indices;
        auto lamda = [x](char ch){ // by doing lamda capture we can use the character x inside this
            return ch == x;
        };
        for(int i = 0; i < n; i++){
            if(any_of(words[i].begin(), words[i].end(), lamda)){
                indices.push_back(i);
            }
        }
        // Learnt new technique in STL -> any_of(), all_of(), none_of() from codestorywithMIK.
        return indices;
    }
};
