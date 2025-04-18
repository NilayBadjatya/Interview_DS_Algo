//Iteratively
class Solution {
public:
    string countAndSay(int n) {
        string t = "1";
        for (int i = 0; i < n-1; i++) {
            string s = "";
            char ch = t[0];
            int count = 0;
            for (int i = 0; i < t.size(); i++) {
                if (t[i] == ch) {
                    count++;
                } else {
                    s += to_string(count) + ch;
                    ch = t[i];
                    count = 1;
                }
            }
            s += to_string(count) + ch;
            t = s;
        }
        return t;
    }
};


//Recursively
class Solution {
public:

    string solve(int n){
        if(n == 1){
            return "1";
        }
        string t = solve(n-1);
        string s = "";
        char ch = t[0];
        int count = 0;
        for(int i = 0; i < t.size(); i++){
            if(t[i] == ch){
                count++;
            }else{
                s += to_string(count) + ch;
                ch = t[i];
                count = 1;
            }
        }
        s += to_string(count) + ch;
        return s;
    }

    string countAndSay(int n) {
        return solve(n);
    }
};
