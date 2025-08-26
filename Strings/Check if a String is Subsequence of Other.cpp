class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        int i = 0, j = 0;
        while(i < n && j < m){
            if(s1[i] == s2[j]){
                i++;
            }
            j++;
        }
        return i == n;
    }
};
