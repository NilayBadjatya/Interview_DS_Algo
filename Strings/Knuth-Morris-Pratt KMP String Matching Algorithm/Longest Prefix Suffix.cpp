class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        int n = s.size();
        vector<int> LPS(n, 0);
        int i = 1, len = 0;
        while(i < n){
            if(s[i] == s[len]){
                len++;
                LPS[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = LPS[len-1];
                }else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        return LPS[n-1];
    }
};
