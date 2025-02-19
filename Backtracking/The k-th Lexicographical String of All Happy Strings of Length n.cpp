class Solution {
public:
    vector<char> dict = {'a', 'b', 'c'};
    void solve(string s, int n, vector<string>& a){
        if(s.size() == n){
            a.push_back(s);
            return;
        }
        if(s.size() > n){
            return;
        }
        for(auto &ch : dict){
            if(s.size() == 0 || s.back() != ch){
                s += ch;
                solve(s, n, a);
                s.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> a;
        solve("", n, a);
        sort(a.begin(), a.end());
        return a.size() < k ? "" : a[k-1];
    }
};
