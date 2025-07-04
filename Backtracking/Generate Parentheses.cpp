class Solution {
public:

    void solve(int open, int close, string t, vector<string>& list){
        if(open == 0 && close == 0){
            list.push_back(t);
            return;
        }
        if(open > 0){
            solve(open-1, close, t + '(', list);
        }
        if(close > open){
            solve(open, close - 1, t + ')', list);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> list;
        solve(n, n, "", list);
        return list;
    }
};
