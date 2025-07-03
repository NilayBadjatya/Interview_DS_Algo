class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.size() < k){
            string temp = word;
            for(int i = 0; i < temp.size(); i++){
                char c = temp[i];
                c++;
                if(c == 26){
                    c = 'a';
                }
                temp[i] = c;
            }
            word += temp;
        }
        cout << word << endl;
        return word[k-1];
    }
};
