class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int i = 0, n = s.size();
        string t = "";
        while(i < n){
            char c = tolower(s[i]);
            if((c >= 97 && c <= 122) || isdigit(c)){
                t += tolower(c);
            }
            i++;
        }
        
        i = 0;
        int j = t.size()-1;
        while(i < j){
            if(t[i++] != t[j--]){
                return false;
            }
        }
        return true;
    }
};
