class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        int i = 0, j = 0;
        while(j < n){
            if(j - i + 1 < 3){
                j++;
            }else if(j - i + 1 == 3){
                if(s[i] == s[i+1] && s[i+1] == s[j]){
                    s[i] = '1';
                }
                j++;
                i++;
            }
        }
        
        string res = "";
        for(auto& ch : s){
            if(ch == '1') continue;
            res += ch;
        }
        return res;
    }
};
