class Solution {
public:

    string toBase(int n, int b){
        string d = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res = "";
        while(n > 0){
            res = d[n%b] + res;
            n /= b;
        }
        return res;
    }

    string concatHex36(int n) {
        string a = toBase(n*n, 16);
        string b = toBase(n*n*n, 36);
        return a+b;
    }
};
