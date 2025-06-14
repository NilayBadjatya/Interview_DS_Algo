class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string s2 = s;
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == '9'){
            i++;
        }

        char c = s[i];
        for(int j = i; j < n; j++){
            if(s[j] == c){
                s[j] = '9';
            }
        }

        c = s2[0];
        for(int j = 0; j < n; j++){
            if(s2[j] == c){
                s2[j] = '0';
            }
        }
        // cout << s << " " << s2;
        return stoi(s) - stoi(s2);
    }
};
