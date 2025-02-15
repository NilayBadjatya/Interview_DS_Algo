class Solution {
public:

    void solve(string s, int i, unordered_set<int>& st, int sum){
        if(i >= s.size()){
            st.insert(sum);
            return;
        }
        if(i != s.size() - 1){
            solve(s, i+1, st, sum);
        }
        solve(s.substr(i+1), 0, st, sum + stoi(s.substr(0, i+1)));
    }

    bool isValid(int i){
        string s = to_string(i*i);
        unordered_set<int> st;
        solve(s, 0, st, 0);
        return st.count(i);
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(isValid(i)){
                sum += (i * i);
                cout << (i*i) << " ";
            }
        }
        return sum;
    }
};
