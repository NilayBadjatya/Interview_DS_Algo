class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), count = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                for(int j = i+1; j < n; j++){
                    if(s2[i] == s1[j]){
                        string temp = s1;
                        swap(temp[i], temp[j]);
                        if(temp == s2) return true;
                    }
                }
            }
        }
        return s1 == s2;
    }
};
