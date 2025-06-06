class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> minChar(n);
        minChar[n-1] = n-1;
        for(int i = n-2; i >= 0; i--){
            if(s[i] <= s[minChar[i+1]]){
                minChar[i] = i;
            }else{
                minChar[i] = minChar[i+1];
            }
        }
        string res = "", t = "";
        for(int i = 0; i < n; i++){
            while(t.size() > 0 && s[minChar[i]] >= t.back()){
                res += t.back();
                t.pop_back();
            }
            t += s[i];
        }
        while(t.size() > 0){
            res += t.back();
            t.pop_back();
        }
        return res;
    }
};
