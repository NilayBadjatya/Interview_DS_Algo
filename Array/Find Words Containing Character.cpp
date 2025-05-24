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
